/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // dp: from top down, the shortest path to a node on ith level is the shortest path to adjacent nodes on
        // i-1 th level + node value on ith level
        // we use just 1 vector to store all levels
        vector<int> shortestPathtoNode((1+triangle.size()) * triangle.size() / 2);
        int levelStart = 0;
        int curLevel = 1;
        int n = shortestPathtoNode.size();
        int shortestPath = INT_MAX;
        while (levelStart<= (n - triangle.size()))
        {
            for (int i = 0; i<curLevel; i++)
            {
                if (levelStart+i - curLevel < levelStart - curLevel + 1) shortestPathtoNode[levelStart+i] = shortestPathtoNode[levelStart+i - curLevel + 1] + triangle[curLevel-1][i];
                else if (levelStart+i - curLevel + 1 == levelStart) shortestPathtoNode[levelStart+i] = shortestPathtoNode[levelStart-1] + triangle[curLevel-1][i];
                else
                {
                    shortestPathtoNode[levelStart+i] = min(shortestPathtoNode[levelStart+i - curLevel + 1], shortestPathtoNode[levelStart+i-curLevel]) + triangle[curLevel-1][i];
                }
                //cout<<shortestPathtoNode[levelStart+i]<<" ";
                if (levelStart == (n - triangle.size()))
                {
                    shortestPath = min(shortestPathtoNode[levelStart+i], shortestPath);
                }
                
                
            }
            levelStart+=curLevel;
            curLevel+=1;
        }
        return shortestPath;
    }
};

int main()
{
    Solution mySol;
    vector<vector<int>> triangle;
    vector<int> temp{-10};
    triangle.push_back(temp);
    cout<<mySol.minimumTotal(triangle)<<endl;
    return 0;
}