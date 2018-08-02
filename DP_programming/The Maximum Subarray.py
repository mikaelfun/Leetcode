'''
We define subsequence as any subset of an array. We define a subarray as a contiguous subsequence in an array.

Given an array, find the maximum possible sum among:

all nonempty subarrays.
all nonempty subsequences.
Print the two values as space-separated integers on one line.

Note that empty subarrays/subsequences should not be considered.

Input Format

The first line of input contains a single integer , the number of test cases.

The first line of each test case contains a single integer .
The second line contains  space-separated integers  denoting the elements of .

Constraints

The subarray and subsequences you consider should have at least one element.

Output Format

Print two space-separated integers denoting the maximum sums of nonempty subarrays and nonempty subsequences, respectively.

Sample Input 0

2
4
1 2 3 4
6
2 -1 2 3 4 -5
Sample Output 0

10 10
10 11
Explanation 0

In the first case: The maximum sum for both types of subsequences is just the sum of all the elements since they are all positive.

In the second case: The subarray  is the subarray with the maximum sum, and  is the subsequence with the maximum sum.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxSubarray function below.
def maxSubarray(arr):
    n = len(arr)
    if n == 0:
        return [0, 0]
    elif n == 1:
        return [arr[0], arr[0]]
    else:
        subSeq = [0 for _ in range(n)]
        subArr = [0 for _ in range(n)]
        subSeq[0] = arr[0]
        subArr[0] = arr[0]
        tempMax = arr[0]

        for i in range(1, n):
            subSeq[i] = max(subSeq[i-1] + arr[i], subSeq[i-1], arr[i])
            subArr[i] = max(subArr[i-1] + arr[i], arr[i])
            if subArr[i] > tempMax:
                tempMax = subArr[i]
        #print (subArr)
        #print ((subSeq))
        return [tempMax, subSeq[-1]]

if __name__ == '__main__':

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = maxSubarray(arr)

        print (result)


'''
2
4
1 2 3 4
6
2 -1 2 3 4 -5

'''
