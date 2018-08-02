/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int n = matrix.size();
        if (n > 0)
        {
            for (int i = 0; i<n; i++)
            {
                vector<int> curRow;
                curRow.push_back(0);
                for (int j = 0; j<matrix[i].size(); j++)
                {
                    curRow.push_back(curRow[curRow.size() - 1] + matrix[i][j]);
                }
                sumEndij.push_back(curRow);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (int i = row1; i<=row2; i++)
        {
            result+=sumEndij[i][col2+1];
            result-=sumEndij[i][col1];
        }
        return result;
    }
    vector<vector<int>> sumEndij;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
 
 
int main()
{
    vector<vector<int>> matrix({{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1},
  {1, 2, 0, 1, 5},
  {4, 1, 0, 1, 7},
  {1, 0, 3, 0, 5}});
    NumMatrix obj = NumMatrix(matrix);
    int param_1 = obj.sumRegion(1,2,3,4);
    cout<<param_1<<endl;
    return 0;
}