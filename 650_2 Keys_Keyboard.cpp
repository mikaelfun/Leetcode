/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Note:
The n will be in the range [1, 1000].
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
    int minSteps(int n) {
        //if n is even, then need to find min steps to get n/2, then just add 2 step, cpy and paste
        //if n is odd, find largest divisor of n, and find min steps to that number, then just add 1+n / div - 1
        vector<int> dp(n+1, 0);
        if (n == 1) return 0;
        if (n <= 3)  return n;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i<=n; i++)
        {
            if (i %2 == 0)
            {
                dp[i] = dp[i/2] + 2;
            }
            else
            {
                int j = i - 1;
                while (i % j != 0)
                {
                    j--;
                }
                if (j != 1)
                {
                    dp[i] = dp[j] + i/j;
                }
                else //prime
                {
                    dp[i] = i;
                }
            }
        }
        for (int i = 0; i<= n; i++) cout<<dp[i]<<" ";
        return dp[n];
    }
};
int main()
{
    Solution mySol;
    int in = 10;
    
    int result = mySol.minSteps(in);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}