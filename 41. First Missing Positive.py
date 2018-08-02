'''
iven an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.


'''
import time
import random
class Solution(object):
    # First approach, set difference O(n), space O(n)
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 1
        maxNum = 0
        numSet = set()
        for each in nums:
            if each > maxNum:
                maxNum = each
            if each > 0:
                numSet.add(each)

        if len(numSet) == 0:
            return 1
        realSet = set(list(range(1,maxNum+1)))
        diffSet = realSet - numSet
        #print (realSet)
        #print (numSet)
        #print (diffSet)
        if not diffSet:
            FirstMissingPos = max(realSet) + 1
        else:
            FirstMissingPos = min(diffSet)
        #print (FirstMissingPos)
        return FirstMissingPos


    # Second approach, Simply use hash O(n), space O(n)
    def firstMissingPositiveHash(self, nums):
        hashTable = {}
        maxNum = 0
        if len(nums) == 0:
            return 1
        for each in nums:
            if each > 0:
                hashTable[each] = 1
            if each > maxNum:
                maxNum = each

        if not hashTable:
            return 1
        for i in range(1, maxNum + 1):
            if i not in hashTable:
                return i
            if i == maxNum:
                return maxNum+1


    # Third approach, Use index time O(n), space O(1)
    def firstMissingPositiveIndex(self, nums):
        # make nums all non negative
        # the first missing element always lies in 1, len(nums)+1
        nums.append(0)
        for i in range(len(nums)):
            if nums[i] < 0 or nums[i] >= len(nums):
                nums[i] = 0
        for i in range(len(nums)):
            nums[nums[i] % len(nums)]+=len(nums) # this will keep the modified nums[i] have the same result when taking the modulo
        for i in range(len(nums)):
            if nums[i] // len(nums) == 0:
                return i
        return len(nums)


if __name__ == "__main__":
    a = Solution()
    nums = []
    #nums = list(range(1000))
    #random.shuffle(heights)
    #nums.append(2)
    for i in range(10000):
        nums.append(random.randint(-5500,5500))

    print (nums)
    start_time = time.time()
    print (a.firstMissingPositive(nums))
    print("--- %s ms done---" % ((time.time() - start_time) * 1000))

    start_time = time.time()
    print (a.firstMissingPositiveHash(nums))
    print("--- %s ms done---" % ((time.time() - start_time) * 1000))


    start_time = time.time()
    print (a.firstMissingPositiveIndex(nums))
    print("--- %s ms done---" % ((time.time() - start_time) * 1000))
