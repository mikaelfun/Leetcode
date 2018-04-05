'''
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        outputSum = 0
        closestTotarget = 1000000
        if len(nums) < 3:
            return 0
        for i in range(len(nums) - 2):
            j = i + 1
            k = len(nums) - 1
            if i>0 and nums[i] == nums[i-1]:
                i+=1
                continue
            while j<k:
                sum = nums[i] + nums[j] + nums[k]
                if abs(sum - target) < closestTotarget:
                    closestTotarget = abs(sum - target)
                    outputSum = sum
                if sum > target:
                    k-=1
                elif sum < target:
                    j+=1
                else:
                    return target
        return outputSum

if __name__ == "__main__":
    a = Solution()
    lst = [-1, 0, 1, 2, -1, -4]
    target = 100
    print (a.threeSumClosest(lst, target))
