"""
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.


"""
class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        out = set()
        for a in nums1:
            if a in nums2:
                out.add(a)
        return list(out)


if __name__ == "__main__":
    l = ["a","b","c"]
    r = ["b","c"]
    print (r in l)
    a = Solution()
