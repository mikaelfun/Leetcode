/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
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
    int numberOfArithmeticSlices(vector<int>& A) {
        // approach 1: dp n^2
        int n = A.size();
        if (n < 3)  return 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false)); //is arith from i to j
        int count = 0;
        for (int i = 0; i<n - 2; i++)
        {
            for (int j = i+2; j<n; j++)
            {
                if (j == i+2)
                {
                    if (A[j] - A[j-1] == A[j-1] - A[j-2])   dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = A[j] - A[j-1] == A[j-1]- A[j-2]? dp[i][j - 1]: false;
                }
                if (dp[i][j])   count++;
            }
        }
        return count;
    }
    int numberOfArithmeticSlices2(vector<int>& A) {
        // approach 2: dp n
        int n = A.size();
        if (n < 3)  return 0;
        vector<int> dp(n, 0);  // # of arith ending at i
        int count = 0;
        for (int i = 2; i<n; i++)
        {
            if (A[i] - A[i-1] == A[i-1] - A[i-2])
            {
                dp[i] = 1;
                dp[i]+=dp[i-1];
            }
            count+=dp[i];
        }
        //for (auto k: dp) cout<<k<<" ";
        return count;
    }
    
};
int main()
{
    Solution mySol;
    vector<int> in = {1,2,3,4,8,9,10};
    
    int result = mySol.numberOfArithmeticSlices2(in);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}