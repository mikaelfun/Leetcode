class Solution:
    digitDict = {
        "2": ["a", "b", "c"],
        "3": ["d", "e", "f"],
        "4": ["g", "h", "i"],
        "5": ["j", "k", "l"],
        "6": ["m", "n", "o"],
        "7": ["p", "q", "r", "s"],
        "8": ["t", "u", "v"],
        "9": ["w", "x", "y", "z"]
    }

    def letterCombinations(self, digits: str) -> List[str]:
        arrlen = len(digits)
        if arrlen == 0:
            return []
        if arrlen == 1:
            if digits[0] in self.digitDict:
                return self.digitDict[digits[0]]
            else:
                return []

        result1 = self.letterCombinations(digits[1:])
        result2 = []
        for each in self.digitDict[digits[0]]:
            for i in range(len(result1)):
                result2.append(each + result1[i])
        return result2
