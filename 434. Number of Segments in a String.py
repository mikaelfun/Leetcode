'''
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
'''

class Solution:
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        words = s.split(" ")
        count = 0
        for each in words:
            if each!="":
                count+=1
        return count
        
if __name__ == "__main__":
    a = Solution()
    str = "Hello, my name is John"
    print (a.countSegments(str))
