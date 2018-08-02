'''
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
'''
class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        '''
        DP: isScramble from ending at j
        either same or palindromic
        '''
        m, n = len(s1), len(s2)
        if m!= n:
            return False
        if set(s1) != set(s2):
            return False

        dp = [False for _ in range(n)]
        stack1 = []
        stack2 = []
        for i in range(0, n+1):
            if stack1 == stack2 and stack1 != []:
                dp[i-1] = True
                stack1 = []
                stack2 = []
            if i == n:
                break
            if not stack1:
                if s1[i] == s2[i]:
                    dp[i] = True
                else:
                    stack1.append(s1[i])
                    stack2.insert(0, s2[i])
            else:
                stack1.append(s1[i])
                stack2.insert(0, s2[i])
        print (dp)
        return dp[i-1]

if __name__ == '__main__':
    a = Solution
    s1, s2 = "abc", "bca"
    print (a.isScramble(a,s1, s2))
