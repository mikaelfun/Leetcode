'''
Input Format

The first line contains two space separated integers  and , the sizes of sequences  and .
The next line contains  space-separated integers .
The next line contains  space-separated integers .

Constraints





Constraints



Output Format

Print the longest common subsequence as a series of space-separated integers on one line. In case of multiple valid answers, print any one of them.

Sample Input

5 6
1 2 3 4 1
3 4 1 2 1 3
Sample Output

1 2 3
Explanation

There is no common subsequence with length larger than 3. And "1 2 3", "1 2 1", "3 4 1" are all correct answers.
'''
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the longestCommonSubsequence function below.
def longestCommonSubsequence(a, b):
    m, n = len(a), len(b)
    dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
    comStr = ""
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if a[i-1] == b[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1

            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    # print(dp)
    curlen = dp[i][j]
    l = []
    while i > 0:
        j = n
        while j > 0:
            if dp[i][j] != curlen:
                j-=1
            elif a[i-1] == b[j-1]:
                l.insert(0, a[i-1])
                curlen-=1
            else:
                j-=1
        i-=1

    #print(comStr)
    return l


if __name__ == '__main__':
    a = [12, 2, 3, 4, 1]
    b = [31, 4, 12, 2, 1, 3]
    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))

    #print (a)
    #print (b)
    result = longestCommonSubsequence(a, b)
    print(result)
