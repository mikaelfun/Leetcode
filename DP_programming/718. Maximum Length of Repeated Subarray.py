'''
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation:
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

'''
class Solution:
    # 1: brute force, n^3
    def findLength1(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        n = len(A)
        maxlen = 0
        for i in range(n):
            if n-i < maxlen:
                break
            for j in range(n):
                if n-j < maxlen:
                    break
                if B[j] == A[i]:
                    l = i
                    r = j
                    while l<n and r<n and A[l] == B[r]:
                        l+=1
                        r+=1
                    maxlen = max(maxlen, l-i)
        return maxlen
    # 2: dp
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        m = len(A)
        n = len(B)
        maxlen = 0
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if A[i] == B[j]:
                    dp[i][j] = dp[i+1][j+1] + 1
                    maxlen = max(maxlen, dp[i][j])

        maxlen = max(max(row) for row in dp)
        return maxlen


if __name__ == '__main__':
    arrA = [2, 4, 3, 6]
    arrB = [2,4,3,8]
    a = Solution()
    print (a.findLength(arrA, arrB))
    # print (findIndex(arrB, 80))
