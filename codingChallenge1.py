def Solution(K, M, A):
        # write your code in Python 3.6
    length = len(A)
    outputLeader = []
    def findLeader(newA):
        dictionary = {}
        for each in newA:
            if each not in dictionary.keys():
                dictionary[each] = 1
            elif dictionary[each] + 1 > len(newA)/2:
                return each
            else:
                dictionary[each] += 1

        # if no leader return -1
        return -1
    for i in range(0,length - K + 1):
        tempA = A[:]
        for j in range(i, i+K):
            tempA[j]+=1
        tempLeader = findLeader(tempA)
        if tempLeader != -1:
            if tempLeader not in outputLeader:
                outputLeader.append(tempLeader)
    return outputLeader

def SolutionStr(s):
    condition = True
    print (s)
    while condition:
        condition = False
        for i in range(0,len(s)-1):
            #print (i)
            if s[i:i+2] in ["AA","BB","CC"]:
                s = s[:i]+s[i+2:]
                condition = True
                print (s)
    return s

def SolutionStr2(s):
    for i in range(0,len(s)-1):
        #print (i)
        if s[i:i+2] in ["AA","BB","CC"]:
            s = s[:i]+s[i+2:]
            return SolutionStr2(s)
    print(s)
    return s


def maxScore(arr):
    arr.sort(reverse=True)
    return maxScoreRec(arr)

def maxScoreRec(arr):
    if len(arr) == 0:
        return 0
    if len(arr) == 1:
        return arr[0]
    if len(arr) == arr.count(arr[0]):
        return arr[0]*len(arr)
    # by this time we definitely have arr[0]+1 as an element
    return max(arr[0]*len(arr)+maxScoreRec(arr[arr.count(arr[0])+arr.count(arr[0]-1):]), maxScoreRec(arr[arr.count(arr[0]):]))






K = 3
M = 5
A = [2,1,3,1,2,2,3]
#print (Solution(K,M,A))
#(SolutionStr2("ACCCCCBBBAAACABCABCBAAABBBAABCBCBABCABCAB"))
print (maxScore(A))
