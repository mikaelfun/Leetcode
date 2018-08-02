'''
Alice is a kindergarten teacher. She wants to give some candies to the children in her class.
All the children sit in a line and each of them has a rating score according to his or her performance in the class.
Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies.
Alice wants to minimize the total number of candies she must buy.

For example, assume her students' ratings are [4, 6, 4, 5, 6, 2].
She gives the students candy in the following minimal amounts: [1, 2, 1, 2, 3, 1]. She must buy a minimum of 10 candies.
'''


#!/bin/python3

import sys

def candies(n, arr):
    # Complete this function
    # the candy for i' th position, is the max(longest increasing subarray ending at i, longest decreasing subarray begging at i)
    if len(arr) == 0:
        return 0
    candy = [0 for _ in arr]
    longestIncreasingSubEnd = [1]
    length = len(arr)
    for i in range(1, length):
        if arr[i] > arr[i-1]:
            longestIncreasingSubEnd.append(longestIncreasingSubEnd[-1] + 1)
        else:
            longestIncreasingSubEnd.append(1)
    longestDecreasingSubBeg = [1]
    for i in range(1, length):
        if arr[length - i -1] > arr[length - i]:
            longestDecreasingSubBeg.insert(0, longestDecreasingSubBeg[0] + 1)
        else:
            longestDecreasingSubBeg.insert(0, 1)
    for i in range(length):
        candy[i] = max(longestIncreasingSubEnd[i], longestDecreasingSubBeg[i])

    return sum(candy)


if __name__ == "__main__":
    n = 10
    arr = [9, 2, 3, 6, 5, 4, 3, 2, 2, 2]
    print (arr)
    #arr = [2,4,2,6,1,7,8,9,2,1]
    result = candies(n, arr)
    print(result)
