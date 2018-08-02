'''
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

'''
import time
import random
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1st approach: find longest subsequence with even negative numebrs
        # 2 2 2 2 -2 2 2 2 -2 2 2 2 2 2 -2 -2 2 2
        # if whole list has even num of neg, then product of whole list
        # if we have 0 in the middle, then we need to divide into multiple lists and call itself to get maxProduct
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        numofNeg = 0
        result = 1
        negIndex = []
        for i in range(len(nums)):
            result *= nums[i]
            if nums[i] == 0:
                temp = max(self.maxProduct(nums[:i]), self.maxProduct(nums[i+1:]))
                if temp>0:
                    return temp
                else:
                    return 0
            if nums[i]<0:
                negIndex.append(i)
                numofNeg += 1

        if numofNeg % 2 == 0:
            #print("even")
            return result
        else:
            return max(self.maxProduct(nums[negIndex[0] + 1:]), self.maxProduct(nums[:negIndex[-1]]))

    def maxProductDP(self,nums):
        '''
        second approach: DP
        performance better in large N, especially with alternating 0's, which will cause maximum recursion in approach 1

        The maximum product ending at index i: is the max(max(max product ending at i-1) * nums[i] , min product ending at i-1)*nums[i]), nums[i])
        :param nums:
        :return:
        '''


        maxp = [0 for x in nums]
        minp = [0 for x in nums]
        #print(max, min)
        maxp[0] = nums[0]
        minp[0] = nums[0]
        product = nums[0]
        for i in range(1, len(nums)):
            maxp[i] = max(max(maxp[i-1] * nums[i], minp[i-1]*nums[i]),nums[i])
            minp[i] = min(min(minp[i-1] * nums[i], maxp[i-1]*nums[i]),nums[i])
            product = max(maxp[i], product)
        #print(maxp)
        #print(minp)
        return product


if __name__ == "__main__":
    a = Solution()
    #nums = [2,2, 2, 2, -2, 2, 2, 2, -2, 2, 2, 2, 2, 2, -2, -2, 2, 2]
    nums = []
    for i in range(5000):
        nums.append(random.randint(-10,10))
        #nums.append(0)
    print (nums)
    start_time = time.time()
    print (a.maxProduct(nums))
    print("--- %s ms done---" % ((time.time() - start_time) * 1000))

    start_time = time.time()
    print (a.maxProductDP(nums))
    print("--- %s ms done---" % ((time.time() - start_time) * 1000))

