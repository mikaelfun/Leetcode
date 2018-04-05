'''
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
'''

class Solution:
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        i = 0
        j = 0
        output = []
        num_of_words = len(words)
        currentLine = ""

        while i<num_of_words and j <num_of_words:
            j = i
            currentLine = ""
            wordlen = 0
            wordcount = 0
            lastline = False
            if i == num_of_words- 1:
                wordlen = len(words[i])
                wordcount = 1
                currentLine = words[i]
                restlen = maxWidth - wordlen
                for x in range(restlen):
                    currentLine+=" "
                output.append(currentLine)
                # print ("exit 1")
                return output


            # print (num_of_words)
            while j < num_of_words:
                # print (j)
                if wordlen+len(words[j]) + wordcount <= maxWidth:
                    wordlen += len(words[j])
                    wordcount += 1
                else:
                    j-=1
                    break
                j+=1
            if j==num_of_words:
                lastline = True
            #print (lastline)
            restlen = maxWidth - wordlen
            k = i
            if lastline:
                while len(currentLine)<maxWidth:
                    if k == j:
                        for x in range(restlen):
                            currentLine+=" "
                        break
                    else:
                        currentLine += words[k]
                        currentLine += " "
                        restlen -= 1
                        k+=1
                output.append(currentLine)
                return output

            else:
                while k<=j:
                    currentLine += words[k]
                    if restlen == 0:
                        break
                    if j == i:
                        for x in range(restlen):
                            currentLine+=" "
                        break

                    if wordcount == 1:
                        continue
                    if restlen // (wordcount-1) * (wordcount-1) < restlen:
                        firstSpacelen = restlen // (wordcount-1) + 1
                    else:
                        firstSpacelen = restlen // (wordcount-1)

                    k += 1

                    for x in range(firstSpacelen):
                        currentLine+=" "
                    restlen -= firstSpacelen
                    wordcount -= 1
                # currentLine,i = self.appendwords(words,i,maxWidth)
                print ("current line: ", currentLine)
                output.append(currentLine)
                #print (i,j)
                i = j + 1
        #print (output)

        return output


if __name__ == "__main__":
    a = Solution()
    words = ["a","b","c","d","e"]
    #words = ["This", "is", "an", "example", "of", "text", "justification."]
    #words = ["What","must","be","shall","be."]
    L = 4
    print (a.fullJustify(words, L))
