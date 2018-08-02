'''
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
'''
import time
import random
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # 1 try: naive O(n) time
        # 2 try: compare target with first element, if greater, search from start, if smaller, search from end
        if len(nums) == 0:
            return -1
        if target>nums[0]:
            i = 1
            while i<len(nums):
                if nums[i] == target:
                    return i
                i+=1
            return -1
        elif target<nums[0]:
            i = len(nums) - 1
            while i>=0:
                if nums[i] == target:
                    return i
                i-=1
            return -1
        else:
            return 0

if __name__ == "__main__":
    a = Solution()
    nums = [4, 5, 6, 7, 0, 1, 2]

    print (nums)
    start_time = time.time()
    print (a.search(nums, 2))
    print("--- %s ms done---" % ((time.time() - start_time) * 1000))

    print (9**0.5)
