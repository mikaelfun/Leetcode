/*
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;
class Solution {
public:
    //1: recursion      time exceeded
    int helper(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int count0 = 0;
        int count1 = 0;
        vector<int> tmp1;
        vector<int> tmp2;
        for (auto k: nums)
        {
            if (k != nums[0] && k!= nums[0] + 1)    tmp1.push_back(k);
            if (k != nums[0] && k!= nums[0] + 2 && k!= nums[0] + 1)    tmp2.push_back(k);
            if (k == nums[0])   count0++;
            if (k == nums[0]+1)   count1++;
        }
        int take0 = count0 * nums[0] + helper(tmp1);
        int take1 =  count1 * (nums[0]+1) + helper(tmp2);
        cout<<"take "<<nums[0]<<":"<<take0<<", take "<<nums[1]<<": "<<take1<<endl;
        return max(take0,take1);                     
    }
    int deleteAndEarn1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // if there is no nums[i]+1 in nums, we can delete nums[i] to get largest earning no matter what
        for (auto i: nums)  cout<<i<<" ";
        cout<<endl;
        return helper(nums);
    }
    //2: dp
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return  0;
        if (n == 1) return nums[0];
        sort(nums.begin(), nums.end());
        
        for (auto i: nums)  cout<<i<<" ";
        cout<<endl;
        unordered_map<int, int> freq;
        vector<int> arr;
        for (auto i: nums)
        {
            if (freq[i])
            {
                freq[i]++;
            }
            else    
            {
                freq[i] = 1;
                arr.push_back(i);
            }
        }
        n = arr.size();
        
        int dp[n+1];
        dp[0] = 0;
        int i = 1;
        int tempmax1 = 0;
        int tempmax2 = 0;
        for (auto each: arr)
        {
            //cout<<each<<endl;
            if (freq[each - 1])
            {
                dp[i] = tempmax2 + each * freq[each];
                tempmax1 = max(tempmax1, dp[i]);
                tempmax2 = max(tempmax2, dp[i-1]);
            }
            else
            {
                dp[i] = tempmax1 + each * freq[each];
                tempmax1 = max(tempmax1, dp[i]);
                tempmax2 = max(tempmax2, dp[i-1]);
            }
            i++;
        }
        for (auto i: dp)    cout<<i<<endl;
        int out= max(dp[n], dp[n-1]);
        return out;
    }
};

int main()
{
    Solution mySol;
    //vector<int> arr = {7,7,12,16,41,48,41,48,11,9,34,2,44,30,27,12,11,39,31,8,23,11,47,25,15,23,4,17,11,50,16,50,38,34,48,27,16,24,22,48,50,10,26,27,9,43,13,42,46,24};
//    vector<int> arr = {4,10,10,8,1,4,10,9,7,6};
    vector<int> arr = {1,1,1,2,4,5,5,5,6};  
    int result = mySol.deleteAndEarn(arr);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}
