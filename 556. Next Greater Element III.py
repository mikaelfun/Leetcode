'''
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer
which has exactly the same digits existing in the integer n and is greater in value than n.
If no such positive 32-bit integer exists, you need to return -1.
Example 1:
Input: 12
Output: 21
'''
class Solution(object):
    def nextGreaterElement(self, n):
        # all elements in descending order, means no next greater element
        strnum = str(n)
        lens = len(strnum)
        output = n
        #print (lens)
        # 2 loops(from right to left), first loop to find first non-descending digit
        # second loop to find first  digit greater than the above digit
        # then swap these digits to get resulting number
        temp = int(strnum[-1:])
        index = lens-1
        for i in range(2,lens + 1,1):
            #print (int(strnum[lens-i]))

            #print (temp)
            if int(strnum[lens-i]) >= temp:
                temp = int(strnum[lens-i])
                if i == lens:
                    break
                continue
            else:
                index = lens-i
                break
        if index == lens - 1:
            return -1
        #print ("index ", index)
        # print (strnum)
        list = []
        for j in strnum:
            # print (j)
            list+=j
        # print (list)

        for i in range(1,lens + 1,1):
            if int(strnum[lens-i]) > int(strnum[index]):
                tmp = strnum[index]
                # print (list)
                list[index] = list[lens-i]
                list[lens-i] = tmp
                # print (list)
                strtemp = ""
                for k in list[:index + 1]:
                    strtemp+=k
                #print (strtemp)

                second = list[index + 1:]
                # print (second)
                second = sorted(second)
                #print (second)
                for j in second:
                    strtemp+=j
                output = int(strtemp)
                if lens>10:
                    return -1
                print (pow(2,31))
                if lens==10:
                    if output> pow(2,31):
                        return -1
                return output




        """
        :type n: int
        :rtype: int
        """

if __name__=="__main__":
    a = Solution
    n = 2147483647
    print (a.nextGreaterElement(a,n))
