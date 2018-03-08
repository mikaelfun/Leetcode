'''
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

'''
class Solution(object):
    def rotate(self, nums, k):
        if k == 0:
            return None
        lens = len(nums)
        if k>lens:
            k = k - lens
        temp = nums[-k:]
        print (temp)
        if lens > 1:
            temp+=nums[:lens-k]
        print (temp)
        del nums[:]
        nums += temp
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
if __name__=="__main__":
    a = Solution
    nums = [1,2]
    a.rotate(a, nums, 3)
    print (nums)
