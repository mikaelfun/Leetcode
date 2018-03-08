"""
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000

"""

class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        output = []
        out = ""
        if not dict:
            output = sentence
            for x in output:
                out=out+x+" "
            out = out[:-1]
            return out

        for eachWord in sentence.split(" "):
            temp = eachWord
            for dic in dict:
                if dic == eachWord[:len(dic)]:
                    #print (temp," temp is at ",eachWord.find(temp))
                    #print (dic," dic is at ",eachWord.find(dic))
                    if len(temp) > len(dic):
                        temp = dic
            output.append(temp)

        for x in output:
            out=out+x+" "
        out = out[:-1]
        print (out)
        return out


if __name__ == "__main__":
    l = ["a","b","c"]
    sentence = "aadsfasf absbs bbab cadsfafs"
    # print ("ca" in "cat")
    a = Solution()
    a.replaceWords(l,sentence)
