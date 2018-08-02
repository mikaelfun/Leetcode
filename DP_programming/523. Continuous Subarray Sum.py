'''
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
'''
class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        n = len(nums)
        multiple = {}
        for i in range(-10000, 10000):
            multiple[i*k] = True
        if n<2:
            return False
        dp =[[0 for _ in range(n+1)] for _ in range(n+1)]
        dp[1][2] = nums[0] + nums[1]
        if k == 0:
            if dp[1][2] == 0:
                #print ("0", dp)
                return True
        elif dp[1][2] in multiple:
            #print ("`", dp)
            return True
        for j in range(3, n+1):
            i = j - 1
            dp[i][j] = dp[i-1][j-1] + nums[j-1] - nums[i-2]
            if k == 0:
                if dp[i][j] == 0:
                    #print ("1", dp)
                    return True
            elif dp[i][j] in multiple:
                #print ("2", dp)
                return True
            i-=1
            while i>0:
                dp[i][j] = dp[i][j-1] + nums[j-1]

                if k == 0:
                    if dp[i][j] == 0:
                        #print ("3", dp)
                        return True
                elif dp[i][j] in multiple:
                    #print ("4", dp)
                    return True
                i-=1
        print (multiple)
        print (dp)
        return False

if __name__ == '__main__':
    a = Solution
    nums  = [0,0]
    k = -1
    print (a.checkSubarraySum(a,nums, k))
