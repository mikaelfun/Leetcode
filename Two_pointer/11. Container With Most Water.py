'''
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
'''
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        '''
        container always ends with a line where immediate right line is less than itself
        starts with a line where immediate left line is less than itself
        '''
        n = len(height)
        l = 0
        r = n-1
        area = 0
        while l<r:
            area = max(area, min(height[l], height[r]) * (r-l))
            if height[l] < height[r]:
                l+=1
            else:
                r-=1
        return area

if __name__ == "__main__":
    a = Solution()
    height = [1,2,3,4,5,6,7,8,9,10]
    print (a.maxArea(height))
