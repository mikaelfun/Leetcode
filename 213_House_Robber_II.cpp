/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return *max_element(nums.begin(), nums.end());
        int curMax = 0;
        vector<int> maxRob(n);
        vector<int> maxRob2(n);
        maxRob[0] = nums[0];
        maxRob[1] = nums[1];
        maxRob[2] = nums[0] + nums[2];
        maxRob2[1] = nums[1];
        maxRob2[2] = nums[2];
        //first loop
        for (int i = 3; i<n ; i++)
        {
            maxRob[i] = max(maxRob[i - 3], maxRob[i-2]) + nums[i];
            maxRob2[i] = max(maxRob2[i - 3], maxRob2[i-2]) + nums[i];
        }
        for (auto x: maxRob)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        for (auto x: maxRob2)
        {
            cout<<x<<" ";
        }
        return max(max(maxRob[n-2],maxRob[n-3]),  max(maxRob2[n-1],maxRob2[n-2]));
            
    }
};


int main()
{
    Solution mySol;
    
    vector<int> n = {1,2,3,4,5};
    int out = mySol.rob(n);
    cout<<out<<endl;
    return 0;
}