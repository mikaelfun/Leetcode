# Complete the function below.
'''
Can do this by using graph. G(V,E)
Think of every sequence in the bank as Vertices
Any two vertices with one different letter form an edge(double-sided)
locate the start/end vertex
find a path from start to end
return -1 if two do not communicate

start may not be part of bank
means we have to add extra vertex in the graph
'''
import sys
import os
import math

# Any two index with difference 10^x * z  where x(0,7), z(1,3)


def findMutationDistance(start, end, bank):
    if start == end:
        return 0
    step = 1
    # initialize queue to be start sequence
    queue = [start]
    endingSeq = [end]
    print (queue, endingSeq)
    toVisit = {x:1 for x in bank}
    print (toVisit)

    if start in toVisit:
        # means start is already visited
        toVisit[start] = 0

    if end not in toVisit:
        return -1

    # using bfs
    while queue:
        # if len(queue) > len(endingSeq):
        #     queue, endingSeq = endingSeq, queue

        # initialize an emtpy nextqueue to store every possible neighbor of all seq in current queue
        nextQueue = []
        for x in queue:
            for i in range(8):
                for t in 'ACGT':
                    if x[i] == t:
                        continue
                    # to get every neighbor of current sequence
                    temp = x[:i] + t + x[i+1:]
                    if temp in endingSeq:
                        # means already found a mutation
                        print (step)
                        return step

                    if toVisit.get(temp, 0):
                        # if it is a neighbor sequence in the bank and is not visited
                        nextQueue.append(temp)
                        toVisit[temp] = 0
        queue = nextQueue
        step += 1
    return -1


if __name__ == "__main__":
    start = input()
    end = input()
    num = input()
    bank = []
    i = 0
    while i < int(num):
        bank.append(input())
        i+=1
    findMutationDistance(start, end, bank)
    # print (neighborIndex(11111111))
    pass

