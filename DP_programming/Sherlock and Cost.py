'''
• Array B containing elements B1, B2,..., Bn is provided as input.

• Elements A1, A2,.., An for array A has to be decided by the coder/code. An element Ai can be any integer such that 1 <= Ai <= Bi.

• Select elements for array A such that it maximizes S (sum of difference between consecutive elements of A).

• Output required : the maximized value S.


Example : Suppose B = [2, 4, 3]. Then 1<=A1<=2, 1<=A2<=4 and 1<=A3<=3. Hence, there are 24 possible options for A, some of them are :

[1, 1, 3]   [1, 2, 3]   [1, 3, 3]   [1, 4, 1]
[2, 1, 2]   [2, 2, 2]   [2, 3, 3]   [2, 4, 1]
Out of all the possible options, A = [1, 4, 1] maximizes S.

Thus, the answer is : |4-1| + |1-4| = 3 + 3 = 6.
'''
#!/bin/python3

import os
import sys

# Complete the cost function below.
def cost(B):
    '''
    The key point is that if a element is surounded by two local maxima; eg. 6. 2. 8,
    then we choose the local maxima to maintain their value, and choose the middle element to be its lowest (1)
    Then we have max difference sum
    if we have multiple elements between 2 local maxima; eg. 6,2,11,1,8, 2
    we choose the local maxima to be its own maximum and neighboring elements to lowest ; 6,1,3,1,8
    and this goes to a subproblem where sum+= 6+8-2 + cost([1,3,1])
    where 3 is local maxima, and we get sum = 3 * 2 -2 = 4. so total sum = 16
    :param B:
    :return:
    '''
    length = len(B)
    if length == 0:
        print (0)
        return 0
    elif length == 1:
        print (0)
        return 0
    elif length == 2:
        print (max(B) - 1)
        return max(B) - 1
    else:
        localMaxIndex = []
        array = B[:]
        index = 1
        if array[index] < array[0]:
            localMaxIndex.append(0)
        while index < length - 1:
            if array[index] >= array[index - 1] and array[index] >= array[index + 1]:
                localMaxIndex.append(index)
            index+=1
        if array[index] > array[index - 1]:
            localMaxIndex.append(index)
        # print(localMaxIndex)
        sum = 0



        while len(localMaxIndex) > 1:
            beg = localMaxIndex.pop(0)
            end = localMaxIndex.pop(0)

            # add outside differnce to sum
            if beg > 0:
                sum += (array[beg] - 1)
            if end < length:
                sum += (array[end] - 1)

            # add inside differnce to sum
            sum+=(array[end] +array[beg] - 2)

            # setting 1 to neighbors
            if end == beg + 2: #only 1 element in between
                array[beg+1] = 1

            elif end >= beg + 3: #only 2 elemetns in between 6,2,4,8, max sum is 8 + 6 - 2 = 12,
                array[beg+1] = 1
                array[end-1] = 1

            # inserting new local maxima resulting form setting 1
            index = end - 2
            while index > beg + 1:
                if array[index] > array[index - 1] and array[index] > array[index + 1] and index not in localMaxIndex:
                    localMaxIndex.insert(0,index)
                index-=1

        # still one local maxima left in stack
        if localMaxIndex:
            index = localMaxIndex.pop(0)
            if index == 0 or index == length - 1:
                sum+=(array[index]-1)
            else:
                sum+=(2*array[index]-2)


    print(sum)
    return sum


if __name__ == '__main__':
    # arrB = [100, 2, 100, 2, 100]
    # arrB = [2, 4, 3]
    # arrB = [1,2,3]
    arrB = [79, 6, 40, 68, 68, 16, 40, 63, 93, 49, 91]
    (cost(arrB))


