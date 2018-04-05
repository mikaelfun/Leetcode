'''
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
'''

class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        shortStr = ""
        for eachChar in s:
            if (eachChar.lower() >= 'a' and eachChar.lower() <= 'z') or (eachChar >= '0' and eachChar <= '9'):
                shortStr+=eachChar.lower()
        # print (shortStr)
        i = 0
        j = len(shortStr) - 1
        while (i<j):
            if shortStr[i]!=shortStr[j]:
                return False
            i+=1
            j-=1
        return True

if __name__ == "__main__":
    a = Solution()
    str = "A man, a plan, a canal: Panama"
    print (a.isPalindrome(str))
