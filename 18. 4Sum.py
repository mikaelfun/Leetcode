'''
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
'''
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        length = len(nums)
        solution = []
        nums.sort()
        print (nums)
        if len(nums) < 4:
            return []

        for i in range(length - 3):
            if i>0 and nums[i] == nums[i-1]:
                continue
            # when first element is too small so that even the biggest sum is smaller than target, we move to next i
            if nums[i]+nums[-1]+nums[-2]+nums[-3] < target:     # this line optimize from 1000ms+ to 173ms, big optimization
                continue
            # when it comes to a point the sum is too large than target, we just break
            if 4 * nums[i] > target:
                break
            for j in range(i + 1, length - 2):
                if j>i+1 and nums[j] == nums[j-1]:
                    continue
                # when second element is too small so that even the biggest sum is smaller than target, we move to next i
                if nums[i]+nums[j]+nums[-1]+nums[-2] < target:
                    continue
                if 3 * nums[j] > target - nums[i]:
                    break
                k = j + 1
                l = length - 1

                while k < l:
                    sum = nums[i] + nums[j] + nums[k] + nums[l]
                    if sum == target:
                        solution.append([nums[i], nums[j], nums[k], nums[l]])
                        while k<l and nums[k-1]==nums[k]:
                            k+=1
                        while k<l and nums[l] == nums[l-1]:
                            l-=1
                        l-=1
                    elif sum > target:
                        while l > k and nums[l] == nums[l-1]:
                            l-=1
                        l-=1
                    else:
                        while l > k and nums[k] == nums[k+1]:
                            k+=1
                        k+=1
        return solution

    def fourSum1(self, nums: [int], target: int) -> [[int]]:
        arrlen = len(nums)
        sumdict = {}
        twosum = [[None for _ in range(arrlen)] for _ in range(arrlen)]
        solution = []
        counted = [[[[None for _ in range(arrlen)] for _ in range(arrlen)] for _ in range(arrlen)] for _ in
                   range(arrlen)]
        for i in range(arrlen):
            for j in range(i + 1, arrlen):
                twosum[i][j] = nums[i] + nums[j]
                if twosum[i][j] not in sumdict:
                    sumdict[twosum[i][j]] = [[i, j]]
                else:
                    sumdict[twosum[i][j]].append([i, j])
                if target - twosum[i][j] in sumdict:
                    for k in sumdict[target - twosum[i][j]]:
                        temp = [k[0], k[1], i, j]
                        temp1 = set(temp)
                        if len(temp1) == 4:
                            temp.sort()
                            if not counted[temp[0]][temp[1]][temp[2]][temp[3]]:
                                solution.append([nums[temp[0]], nums[temp[1]], nums[temp[2]], nums[temp[3]]])
                                counted[temp[0]][temp[1]][temp[2]][temp[3]] = 1
        return solution

if __name__ == "__main__":
    a = Solution()
    lst = [-3,-2,-1,0,0,1,2,3]
    target = 0
    print (a.fourSum1(lst, target))
