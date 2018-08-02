'''
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
'''
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        dp = [[99999 for _ in range(n+1)] for _ in range(m+1)]

        if len(grid) == 0:
            return 0
        dp[1][1] = grid[0][0]

        for i in range(1,m+1):
            for j in range(1,n+1):
                if i == 1 and j == 1:
                    continue
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1]

        # print (dp)
        return dp[i][j]

if __name__ == '__main__':
    a = Solution
    Grid = [
  [1,3,1],
  [1,5,1],
  [4,2,1]
]

    print (a.minPathSum(a,Grid))
