'''
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

'''
class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        n = len(s)
        output = []
        dic = {}
        if n <=10:
            return output
        for i in range(n-9):
            if s[i:i+10] in dic:
                dic[s[i:i+10]]+=1
            else:
                dic[s[i:i+10]] = 1
        for each in dic:
            if dic[each] > 1:
                output.append(each)
        return output

if __name__ == '__main__':
    a = Solution
    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
    print (a.findRepeatedDnaSequences(a,s ))
