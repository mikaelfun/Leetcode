/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
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
    int combinationSum4(vector<int>& nums, int target) {
        //dp[i]: num of comb of i
        sort(nums.begin(), nums.end());
        int dp[target + 1];
        dp[0] = 1;
        for (int i = 1; i< target + 1; i++)
        {
            dp[i] = 0;
            for (int j = 0; j< nums.size() && nums[j] <= i ; j++)
            {
                dp[i] += dp[i-nums[j]];
            }
        }
        for (auto i: dp)    cout<<i<<" ";
        cout<<endl;
        return dp[target];
    }
};
int main()
{
    Solution mySol;
    vector<int> arr = {1,2};
    int in = 10; 
    int result = mySol.combinationSum4(arr, in);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}