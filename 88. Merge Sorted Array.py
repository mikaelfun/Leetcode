'''
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
'''

class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        '''
        [1,5,6]
        [2,3,4]
        '''
        i = 0
        j = 0
        numsout = []
        while 1:
            if j == n and i == m:
                break
            elif j == n:
                for each in nums1[i:]:
                    numsout.append(each)
                break
            elif i == m:
                for each in nums2[j:]:
                    numsout.append(each)
                break
            elif nums1[i] > nums2[j]:
                numsout.append(nums2[j])
                j+=1
            else:
                numsout.append(nums1[i])
                i+=1
        for k in range(0, m+n):
            nums1[k]= numsout[k]
        print (nums1)



if __name__ == "__main__":
    a = Solution()
    nums1 = [0,0,0,0]
    m = 0
    nums2 = [2,3,4,7]
    n = 4
    print (a.merge(nums1,m, nums2,n))
    print (nums1)
