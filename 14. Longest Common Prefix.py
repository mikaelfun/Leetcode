class Solution:
    def longestCommonPrefix(self, strs: [str]) -> str:
        arrlen = len(strs)
        if arrlen == 0:
            return ""
        if arrlen == 1:
            return strs[0]
        minLen = len(strs[0])
        for i in range(len(strs[0])):
            if i == minLen:
                return strs[0][:i]
            for j in range(1, arrlen):
                jlen = len(strs[j])
                minLen = min(minLen, jlen)
                if i >= jlen:
                    return strs[0][:i]
                if strs[0][i] != strs[j][i]:
                    return strs[0][:i]

        return strs[0]

a = Solution()
b = ["flower","flow","flight"]
print (a.longestCommonPrefix(b))