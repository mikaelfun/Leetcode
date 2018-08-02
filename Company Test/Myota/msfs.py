'''
3. MSFS
'''
'''
Reference:
1. get PID: https://stackoverflow.com/questions/8281345/how-to-get-the-current-linux-process-id-from-the-command-line-a-in-shell-agnosti
2. storing and loading meta data using json: https://docs.python.org/3/tutorial/inputoutput.html#saving-structured-data-with-json
3. for file writing in the middle: https://ubuntuforums.org/showthread.php?t=1847959
4. file locking between processes: https://github.com/dmfrey/FileLock/blob/master/filelock/filelock.py

'''
import os
import json
import time
from filelock import FileLock
# rootPath path for data
rootPath = "MSFS\\data\\directory"
# metaPath path for metadata
metaPath = "MSFS\\meta"
# fragments file size
fragSize = 16
# maximum file size
fileMaxSize = 1024


'''
Creating a directory by recursively checking if parent directory exists
'''


def mkdir(filepath):
    if os.path.isdir(filepath):
        return None             # exit if exists
    
    if "\\" not in filepath:    # no parent directory
        if not os.path.isdir(filepath):
            os.mkdir(filepath)
    else:
        direct = filepath.split("\\")
        directSofar = direct[0]
        i = 1
        while True:
            if not os.path.isdir(directSofar):
                os.mkdir(directSofar)
            if i == len(direct):
                break
            directSofar += ("\\" + direct[i])
            i += 1


def load_info(f_name):
    try:
        f = open(f_name)
        info = json.loads(f.read())
        return info
    except:
        return {}

'''
references:
1. locking: https://pypi.org/project/filelock/
'''


def save_info(f_name, info):
    f = open(f_name, 'w')
    f.write(json.dumps(info))
    f.close()

'''
returns the full path and partial path of the given file path
'''


def fullPartialPath(filepath):
    if filepath[0] == '\\':
        if rootPath == filepath[:len(rootPath)]:        # already a full path
            path = filepath[1:]
            partial = filepath[len(rootPath)+2:]
        else:
            path = os.path.join(rootPath, filepath[1:])
            partial = filepath[1:]
    else:
        if rootPath == filepath[:len(rootPath)]:        # already a full path
            path = filepath
            partial = filepath[len(rootPath)+1:]
        else:
            path = os.path.join(rootPath, filepath)
            partial = filepath
    partial = partial.replace("\\", "_")
    actual = find_actual_filename(filepath)
    return path, partial, actual

'''
Find parent directory given a file path
'''


def find_parent_dir(fullpath):
    for index in range(len(fullpath) - 1, -1, -1):
        if fullpath[index] == "\\" and index != 0:
            return fullpath[:index]
    return ""

'''
Find the actual file name from a full path
'''


def find_actual_filename(fullpath):
    for index in range(len(fullpath) - 1, -1, -1):
        if fullpath[index] == "\\":
            if index != len(fullpath) - 1:
                return fullpath[index + 1:]
            else:
                print ("Invalid filepath!")
                return ""
    return fullpath

'''
Find the corresponding fragment file name given a full file path and its fragment number
'''


def create_frag_file(fullpath, fragNum):
    # locate . in file name if there is one
    path = fullpath+"_"+str(fragNum)
    for index in range(len(fullpath) - 1, -1, -1):
        if fullpath[index] == "\\":
            break
        elif fullpath[index] == ".":
            path = fullpath[:index] + "_" + str(fragNum) + fullpath[index:]
            break
    # print (fragNum, fullpath, path)
    return path

'''
Open a file, returns the file's full path to substitute an file object
append current process id to its metadata to avoid multiple opens
'''


def Open(filepath):
    fullpath, partial, actual = fullPartialPath(filepath)
    # print (fullpath, partial)
    # lock between load and save block

    # Bug: locking non existing file prevents the file from being created
    mkdir(rootPath)
    mkdir(metaPath)
    f_name = os.path.join(metaPath, partial + ".json")
    lock = FileLock(f_name+".lock", timeout = 10)
    with lock.acquire():
        fileInfo = load_info(f_name)
        if not fileInfo:
            fileInfo = {
                        "metaFileName": partial,
                        "actualFileName": actual,
                        "filesize": 0,
                        "filepath": fullpath,
                        "frag-num": 1,
                        "opened-by-process": [],
                        }
            save_info(f_name, fileInfo)
            # create new file
            fragpath = create_frag_file(fullpath, 0)
            parent_dir = find_parent_dir(fullpath)
            mkdir(parent_dir)
            # print (fragpath)
            f = open(fragpath, "w")
            f.close()

        curPID = os.getpid()
        # print (curPID)
        if curPID in fileInfo["opened-by-process"]:
            print ("Cannot open twice by the same PID")
            return None
        else:
            fileInfo["opened-by-process"].append(curPID)
            # print (fileInfo)
            save_info(f_name, fileInfo)
            return fullpath

'''
Close a file
'''


def Close(file):
    if not file:
        print ("file is none")
        return None
    fullpath, partial, actual = fullPartialPath(file)
    f_name = os.path.join(metaPath, partial + ".json")
    lock = FileLock(f_name+".lock", timeout=10)
    with lock.acquire():
        fileInfo = load_info(f_name)
        if not fileInfo:        # file does not exist
            print ("Close failed, file not exist")
        else:
            curPID = os.getpid()
            if curPID not in fileInfo["opened-by-process"]:
                print ("Cannot close a file not opened by this PID")
            else:
                fileInfo["opened-by-process"].remove(curPID)
                # print (fileInfo)
                save_info(f_name, fileInfo)
                print ("[", curPID, "] successfully closed file[", fullpath,"]")

    return None

'''
Reading a file from specific fragment and starting index from that fragment
'''


def readFragFrom(fullpath, frag, start, bytesToRead):
    path = create_frag_file(fullpath, frag)
    if not os.path.exists(path):
        # print("EOF")
        # print("readFragFrom: frag file does not exist!")
        return ""
    else:
        fragFileLock = FileLock(path+".lock", timeout = 10)
        # no need to lock the file since multiple read processes can happen simultaneously
        # and if writer locks this frag, it cannot be read until the writer releases the lock
        while True:
            if fragFileLock.is_locked:
                # time.sleep(0.001)
                continue
            else:
                f = open(path, 'r')
                if start + bytesToRead <= fragSize:
                    f.read(start)
                    data = f.read(bytesToRead)
                else:
                    f.read(start)
                    data = f.read()
                    if not data:
                        # print("EOF")
                        return ""
                    if data[-1] == '\n':
                        data = data[:-1]
                    nextFrag = readFragFrom(fullpath, frag + 1, 0, bytesToRead - fragSize + start)
                    data += nextFrag
                return data

'''
Reading a file from an offset for bytesToRead bytes
'''


def ReadAt(file, bytesToRead, offset):
    fullpath, partial, actual = fullPartialPath(file)
    f_name = os.path.join(metaPath, partial + ".json")
    metaLock = FileLock(f_name+".lock", timeout = 10)
    while True:
        if metaLock.is_locked:
            # time.sleep(0.001)
            continue
        else:
            fileInfo = load_info(f_name)
            if not fileInfo:
                continue
            if os.getpid() not in fileInfo["opened-by-process"]:
                print ("ReadAt failed, you have to open it first")
                return None
            fragStart = offset // fragSize
            start = offset % fragSize
            fragEnd = (offset + bytesToRead) // fragSize
            if fragEnd < (offset + bytesToRead) / fragSize:
                fragEnd+=1
            data = readFragFrom(fullpath, fragStart, start, bytesToRead)
            if data:
                return data
            else:
                return None



'''
Writing a file from a specific fragment and starting index
'''

def writeFragFrom(fullpath, data, frag, start, bytesToWrite, l, r):    # r exclusive
    path = create_frag_file(fullpath, frag)
    if not os.path.exists(path):
        # print (path)
        print ("writeFragFrom: frag file does not exist!")
        return False
    else:
        fragLock = FileLock(path+".lock", timeout = 10)
        with fragLock.acquire():
            f = open(path, 'r+')
            if start + bytesToWrite <= fragSize and r-l+start <= fragSize:
                f.seek(start)
                f.write(data[l:r])
            else:
                f.seek(start)
                f.write(data[l: l + fragSize - start])
                writeFragFrom(fullpath, data ,frag + 1, 0, bytesToWrite - fragSize + start, l + fragSize - start, r)
            f.close()
            return True

'''
get all fragments of this file and merge it into one buffer
'''


def getBuffer(fullpath, size):
    data = readFragFrom(fullpath, 0, 0, size)
    return data

'''
Write when new length exceeds current length from a specific fragment
'''


def writeFullBuffer(fullpath, buffer, startingFrag):
    newLen = len(buffer)
    allFrag = newLen // fragSize
    if newLen / fragSize > allFrag:
        allFrag += 1

    for i in range(startingFrag, allFrag):
        fragFileName = create_frag_file(fullpath, i)
        if not os.path.exists(fragFileName):
            f = open(fragFileName, 'w')
            f.close()
        writeFragFrom(fullpath, buffer, i, 0, fragSize, i * fragSize, i * fragSize + fragSize)
    return newLen, allFrag

'''
Write data from an offset
'''


def WriteAt(file, data, offset):
    # print (file.opened)
    fullpath, partial, actual = fullPartialPath(file)
    bytesWritten = len(data)
    f_name = os.path.join(metaPath, partial + ".json")
    metaLock = FileLock(f_name+".lock", timeout = 10)
    # To Optimize: If writing does not exceed filesize, no need to lock metafile
    # hence allowing multiple processes to write to the same file if they write
    # different fragments of the file
    with metaLock.acquire():
        fileInfo = load_info(f_name)
        if not fileInfo:        # file does not exist
            print ("WriteAt failed, file not exist")
            return -1
        elif os.getpid() not in fileInfo["opened-by-process"]:
            print ("WriteAt failed, you have to open it first")
            return -1
        else:
            if fileInfo["filesize"] < offset + bytesWritten:       # data to write exceeds current filesize
                '''
                    strategy: merge all fragments into one file, and write new file, and split into fragments
                '''
                if offset + bytesWritten > fileMaxSize:
                    print ("writing too many")
                    bytesWritten = fileMaxSize - offset

                buffer = getBuffer(fullpath, fileInfo["filesize"])
                if len(buffer) < offset:
                    print ("Offset Invalid!")
                    return -1
                elif offset == 0:
                    buffer = data + buffer
                elif offset == len(buffer):     # appending
                    buffer += data
                else:
                    buffer = buffer[:offset] + data + buffer[offset:]
                if len(buffer) > fileMaxSize:
                    buffer = buffer[:fileMaxSize]
                # frag file starting to be modified
                startingFrag = offset // fragSize
                fileInfo["filesize"], fileInfo["frag-num"] = writeFullBuffer(fullpath, buffer, startingFrag)
                save_info(f_name, fileInfo)
                return bytesWritten
            else:                                           # data to write is within current filesize
                frag = offset // fragSize
                start = offset % fragSize
                if writeFragFrom(fullpath, data, frag, start, bytesWritten, 0, len(data)):
                    save_info(f_name, fileInfo)
                    return len(data)
                else:
                    save_info(f_name, fileInfo)
                    return -1
