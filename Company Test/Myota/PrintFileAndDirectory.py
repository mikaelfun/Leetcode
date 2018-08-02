import os, sys

'''
2. print name of all directories and files (including all sub-directories).
references: https://stackoverflow.com/questions/8933237/how-to-find-if-directory-exists-in-python
'''


def print_all_dir_file(directory):
    if not os.path.isdir(directory):
        print ("Invalid Directory: ", directory)
        return None
    for files in os.listdir(directory):
        print(files)
        if os.path.isdir(os.path.join(directory, files)):
            print_all_dir_file(os.path.join(directory, files))

if __name__ == "__main__":
    try:
        dir = sys.argv[1]
        print ("Printing from given directory: ", dir)
        print_all_dir_file(dir)
    except:
        print ("Printing from current working directory: ", os.getcwd())
        print_all_dir_file(os.getcwd())
