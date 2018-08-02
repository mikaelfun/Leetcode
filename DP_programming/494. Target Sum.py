'''
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
'''
class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        '''
        1st: recursive, time out
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            if nums[0] == 0 and S == 0:
                return 2
            elif nums[0] == S or nums[0] == (0-S):
                return 1
            else:
                return 0
        else:
            return self.findTargetSumWays(nums[:-1], S-nums[-1]) + self.findTargetSumWays(nums[:-1], S+nums[-1])
        '''
        '''
        2ns: dp, dp = [{sum: ways}], dp[i] is all sums that ending at i th of nums and their ways
        
        '''
        n = len(nums)
        if n == 0:
            return 0
        dp =[{} for _ in range(n)]
        if nums[0] == 0:
            dp[0][nums[0]] = 2
        else:
            dp[0][nums[0]] = 1
            dp[0][-nums[0]] = 1
        for i in range(1, n):
            for each in dp[i-1]:
                if nums[i] == 0:
                    if each not in dp[i]:
                        dp[i][each] = dp[i-1][each] * 2
                    else:
                        dp[i][each] += (dp[i-1][each] * 2)
                else:
                    if each + nums[i] not in dp[i]:
                        dp[i][each + nums[i]] = dp[i-1][each]
                    else:
                        dp[i][each + nums[i]] += dp[i-1][each]
                    if each - nums[i] not in dp[i]:
                        dp[i][each - nums[i]] = dp[i-1][each]
                    else:
                        dp[i][each - nums[i]] += dp[i-1][each]

        # print (dp)
        if S in dp[-1]:
            return dp[-1][S]
        else:
            return 0

if __name__ == '__main__':
    a = Solution
    nums = [1,1,1,1,1]

    S = 3
    print (a.findTargetSumWays(a,nums, S))
