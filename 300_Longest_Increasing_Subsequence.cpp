/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longestAti(nums.size(), 1);
        int lis = 1;
        if (nums.size() == 0)
        {
            return 0;
        }
        for (int i = 0; i<nums.size(); i++)
        {
            int j = i-1;
            while (j>=0)
            {
                if (nums[j] < nums[i])
                {
                    longestAti[i] = max(longestAti[j] + 1, longestAti[i]);
                    lis = max(lis, longestAti[i]);
                }
                j--;
            }
        }
        return lis;
    }
};


int main()
{
    Solution mySol;
    vector<int> vec({10,9,2,5,3,7,101,18});
    int out = mySol.lengthOfLIS(vec);
    cout<<out<<endl;
    return 0;
}