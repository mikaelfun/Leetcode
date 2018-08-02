#!/bin/python3

import os
import sys

#
# Complete the summingPieces function below.
#
def summingPieces(arr):
    #
    # Write your code here.
    #
    sum1 = [0 for _ in arr]
    ways = [0 for n in range(0,len(arr))]
    ways.insert(0, 1)
    ways[1] = 1
    for i in range(2, len(arr) + 1):
        ways[i] = ways[i-1] * 2 % 1000000007

    sum1[0] = arr[0]
    currentSum = sum1[0]
    # store summation of array from i to j
    internalSum = [[0 for _ in arr] for _ in arr]
    for i in range(len(arr)):
        for j in range(i, len(arr)):
            if i == j:
                internalSum[i][j] = arr[i]
            else:
                internalSum[i][j] = internalSum[i][j-1]+arr[j]

    # specialHelper = [0 for _ in arr]
    # for i in range(1, len(arr)):
    #     if i == 1:
    #         specialHelper[i] = internalSum[0][1] * 2 * ways[0]
    #     else:
    #         specialHelper[i] = specialHelper[i-1] + internalSum[0][i] * (i+1) * ways[0]

    for i in range(1, len(arr)):
        sum1[i] = ways[i] * arr[i] + currentSum
        for j in range(2, i+2):
            sum1[i] += internalSum[i-j + 1][i] * j * ways[i -j + 1]
        #sum1[i] += specialHelper[i]
        sum1[i] %= 1000000007
        currentSum+=sum1[i]
    print (internalSum)
    print (sum1)
    return sum1[len(arr) - 1]

'''
if __name__ == '__main__':
    arr = [4, 2, 9, 10, 1]

    result = summingPieces(arr)
'''

if __name__ == '__main__':

    arr_count = int(input())

    arr = list(map(int, input().rstrip().split()))

    print (summingPieces(arr))

