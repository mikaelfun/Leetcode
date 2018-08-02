import msfs
import time

'''
Reader process
'''


if __name__ == "__main__":
    f1 = msfs.Open("test.txt")
    i = 0
    while True:
        data = msfs.ReadAt(f1, 15, i)
        print (data)
        i+=1
        if i > 1024:
            i = 0
        time.sleep(0.003)
    msfs.Close(f1)
