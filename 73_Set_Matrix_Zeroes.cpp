/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <map>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        if (m == 0)
        {
            return;
        }
        int n = matrix[0].size();
        if (n == 0)
        {
            return;
        }
        map<int, int> zeroedRow;
        map<int, int> zeroedCol;
        for (int i = 0; i<m; i++)
        {
            zeroedRow[i] = 0;
        }
        for (int i = 0; i<n; i++)
        {
            zeroedCol[i] = 0;
        }
        
        for (int i = 0; i<m; i++)
        {
            for (int j = 0; j<n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroedRow[i] = 1;
                    zeroedCol[j] = 1;
                }
                
            }
        }
        for (int i = 0; i<m; i++)
        {
            if (zeroedRow[i])
            {
                for (int j = 0; j<n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i<n; i++)
        {
            if (zeroedCol[i])
            {
                for (int j = 0; j<m; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        
        return;
    }
};

int main()
{
    Solution mySol;
    vector<vector<int>> a = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
    int m = a.size();

    int n = a[0].size();

    //mySol.search(a, 4);
    mySol.setZeroes(a);
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}