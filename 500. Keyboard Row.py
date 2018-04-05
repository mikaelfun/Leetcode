'''
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
'''

class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        firstRow = set("qwertyuiop")
        #print (firstRow)
        secondRow = set("asdfghjkl")
        thirdRow = set("zxcvbnm")
        output = []
        for each in words:
            temp = set(str(each.lower()))
            #print (temp)
            if temp.issubset(firstRow):
                output.append(each)
            elif temp.issubset(secondRow):
                output.append(each)
            elif temp.issubset(thirdRow):
                output.append(each)
            else:
                pass
        return output


if __name__ == "__main__":
    a = Solution()
    words = ["Hello", "Alaska", "Dad", "Peace"]

    print(a.findWords(words))
