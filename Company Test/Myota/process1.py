import msfs
import time
import random

'''
Writer process
'''


if __name__ == "__main__":
    f1 = msfs.Open("test.txt")

    i = 0
    while True:
        print (msfs.WriteAt(f1, str(random.randint(1, 10000)), i))
        i+=1
        if i > 1024:
            i = 0
        time.sleep(0.01)

    msfs.Close(f1)

