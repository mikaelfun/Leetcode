/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // numSquare(n) = best(numSquare(n- a*x^2) + a)
        vector<int> arr(n+1, INT_MAX);
        if (n < 4) return n;
        arr[0] = 0;
        arr[1] = 1;
        //arr[4] = 1;
        for (int i = 2; i<=n; i++)
        {
            for (int j = 1; j*j <= i; j++)
            {
                arr[i] = min(arr[i], (arr[i - j*j] + 1));
            }
        }
        for (int i = 1; i<=n; ++i)
        {
            cout<<i<<": "<<arr[i]<<endl;
        }
        return arr[n];
    }
};



int main()
{
    Solution mySol;
    int n = 1994;
    int out = mySol.numSquares(n);
    cout<<out<<endl;
    return 0;
}