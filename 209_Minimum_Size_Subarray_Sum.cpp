/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
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
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        if (n == 0) return 0;
        int curSum = nums[r];
        while (r<n)
        {
            if (curSum < s)
            {
                r++;
                curSum += nums[r];
            }
            else
            {
                minLen = min(minLen, r-l + 1);
                curSum -= nums[l];
                l++;
            }
        }
        if (minLen == INT_MAX)  minLen = 0;
        return minLen;
    }
};

int main()
{
    Solution mySol;
    int s = 300;
    vector<int> arr = {7,7,12,16,41,48,41,48,11,9,34,2,44,30,27,12,11,39,31,8,23,11,47,25,15,23,4,17,11,50,16,50,38,34,48,27,16,24,22,48,50,10,26,27,9,43,13,42,46,24};

    
    int result = mySol.minSubArrayLen(s, arr);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}
