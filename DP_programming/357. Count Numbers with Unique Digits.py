'''
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.


'''
class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp =[0 for _ in range(n+1)]
        dp[0] = 1
        if n == 0:
            return 1
        dp[1] = 10

        for i in range(2, n+1):
            if i >= 11:
                dp[i] = dp[i-1]
            else:
                dp[i] = dp[i-1] * (10 - i) + sum(dp[:i])
        print (dp)
        return dp[-1]

if __name__ == '__main__':
    a = Solution
    n = 5
    print (a.countNumbersWithUniqueDigits(a,n))
