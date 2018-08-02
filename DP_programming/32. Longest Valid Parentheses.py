'''
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
'''
import numpy as np
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        '''
        valid parentheses substring must have even length
        dp[n+1][n+1] be longest valid substr between i and j, i,j = 1,..., n
        
        '''
        n = len(s)
        if n <2:
            return 0
        dp = [0 for _ in range(n)]
        for j in range(1, n):
            if s[j] == ')':
                if dp[j-1] == 0:
                    '''
                    ()() case
                    '''
                    if s[j-1] == '(':
                        dp[j] = 2 + dp[j-2]

                else:
                    '''
                    (()) case
                    '''

                    if j-1 >= dp[j-1] and s[j-1-dp[j-1]] == '(':
                        dp[j] = dp[j-1]+2
                        m = j - dp[j]
                        while m>=0 and dp[m] != 0:
                            dp[j]+=dp[m]
                            m = m - dp[m]

        print (dp)
        return max(dp)

if __name__ == '__main__':
    a = Solution
    arr = "()(())"

    print (a.longestValidParentheses(a,arr))
