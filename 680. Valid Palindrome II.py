'''
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
'''
class Solution:
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        i = 0
        j = len(s) - 1
        while i<j:
            if s[i] != s[j]:
                a,b = s[i:j], s[i+1:j+1]
                return a == a[::-1] or b == b[::-1]
            i+=1
            j-=1
        return True

if __name__ == "__main__":
    a = Solution()
    str = "abca"
    print (a.validPalindrome(str))

