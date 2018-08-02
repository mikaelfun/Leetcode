'''
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
'''
import time
import random
class Solution(object):
    # 1st approach, naive search, linear O(n)
    def searchInsert_1(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        for i in range(len(nums)):
            if nums[i] >= target:
                return i
        return i+1

    # 2nd approach, binary search, Log(N)
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        low,hi = 0, len(nums) - 1
        mid = (low + hi) // 2
        #print (low, hi, mid,mid1)
        if len(nums) == 1:
            if nums[0] >= target:
                return 0
            else:
                return 1
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            return self.searchInsert(nums[:mid],target)

        else:
            return mid+1+self.searchInsert(nums[mid+1:],target)

    # 3rd approach, binary search, Log(N) without using recursive call to waste call stack
    def searchInsert_2(self, nums, target):
        if len(nums) == 0:
            return 0
        low,hi = 0, len(nums)
        while (low<= hi):
            mid = (low + hi) // 2
            #print (mid, low, hi)
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                if mid == 0:
                    return 0
                hi = mid - 1
            else:
                if mid == len(nums)-1:
                    return len(nums)
                low = mid + 1
        return low

if __name__ == "__main__":
    a = Solution()
    nums = []
    for i in range(5000):
        temp = random.randint(0,100000)
        if temp not in nums:
            nums.append(temp)
    nums.sort()
    #nums = [1,3]
    #print (nums)
    target =  91911
    #target = 2
    start_time = time.time()
    print (a.searchInsert_1(nums, target))
    print("--- %s ms done---" % ((time.time() - start_time) * 1000))


    start_time = time.time()
    print (a.searchInsert(nums, target))
    print("--- %s ms done---" % ((time.time() - start_time) * 1000))

    start_time = time.time()
    print (a.searchInsert_2(nums, target))
    print("--- %s ms done---" % ((time.time() - start_time) * 1000))
