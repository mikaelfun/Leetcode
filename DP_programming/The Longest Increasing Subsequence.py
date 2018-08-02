#!/bin/python3

import sys

def longestIncreasingSubsequence(arr):
    # Complete this function
    '''
    dp: O(N^2)
    :param arr:
    :return:
    '''
    dp = [] # longest sub ending at i
    length = len(arr)
    for i in range(length):
        dp.append(1)
    for i in range(1, length):
        for j in range(i):
            if arr[i] > arr[j] and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
    output = max(dp)
    #print (output)
    return output

def findIndex(dp, target):
    '''
    replace the first element >= target, with target
    :param dp:
    :param target:
    :return:
    '''
    l, r = 0, len(dp) - 1
    while r > l:
        mid = (l + r) // 2
        if dp[mid] == target:
            return mid
        elif dp[mid] > target:
            r = mid
        else:
            l = mid + 1
    return r

def longestIncreasingSubsequence2(arr):
    # Complete this function
    '''
    dp: O(NlogN)
    :param arr:
    :return:
    '''
    dp = [] # dp_i is the min element in arr that ends a increasing subsequence with length i
    length = len(arr)
    for i in range(0, length):
        if len(dp) == 0 or arr[i] > dp[-1]:
            dp.append(arr[i])
        else:
            # find the first in dp >= arr[i], replace it with arr[i]
            index = findIndex(dp, arr[i])
            dp[index] = arr[i]
    output = len(dp)
    print (dp)
    return output



if __name__ == '__main__':
    # arrB = [100, 2, 100, 2, 100]
    # arrB = [2, 4, 3]
    arrB = [2,7,4,3,8]
    # arrB = [79, 6, 40, 68, 68, 16, 40, 63, 93, 49, 91]
    # arrB.sort()
    print (arrB)
    print (longestIncreasingSubsequence(arrB))
    print (longestIncreasingSubsequence2(arrB))
    # print (findIndex(arrB, 80))
