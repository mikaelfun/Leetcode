'''
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
'''
class Solution(object):
    # trick is to count all none 1 neighbors(including walls) of all 1s
    def noneoneNeighbor(self, grid, r, c):
        count = 0
        wid = len(grid[0])
        hei = len(grid)
        if r==0:
            count+=1
        if r==hei-1:
            count+=1
        if c==0:
            count+=1
        if c==wid-1:
            count+=1
        if r>0 and grid[r-1][c] == 0:
            count+=1
        if c>0 and grid[r][c-1] == 0:
            count+=1
        if r<hei-1 and grid[r+1][c] == 0:
            count+=1
        if c<wid-1 and grid[r][c+1] == 0:
            count+=1
        return count


    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        perimeter = 0
        for r in range(0,len(grid)):
            for c in range(0, len(grid[0])):
                if grid[r][c] == 1:
                    perimeter += self.noneoneNeighbor(grid, r, c)
        return perimeter

if __name__ == "__main__":
    a = Solution()
    island  = [[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
    print (a.islandPerimeter(island))

