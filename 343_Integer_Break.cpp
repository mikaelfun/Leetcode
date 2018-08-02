/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
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
    int integerBreak(int n) {
        int dp[n+1]; // biggest product for integer i
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i<=n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j < i; j++)
            {
                if (dp[j] > j)
                {
                    dp[i] = max(dp[i], dp[j] * (i - j));
                }
                else
                {
                    dp[i] = max(dp[i], j * max(dp[(i - j)], i - j));
                }
                
            }
            cout<<i<<":"<<dp[i]<<" ";
        }
        
        return dp[n];
    }
};
int main()
{
    Solution mySol;
    int in = 52;
    int result = mySol.integerBreak(in);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}