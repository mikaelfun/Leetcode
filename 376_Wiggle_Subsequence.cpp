/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
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
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<pair<int, int>> dp(n);  // 1->prev decrease, -1->prev increase, 0 prev equal
        dp[0] = make_pair(1, 0);
        int maxlen = 0;
        if (nums[1] != nums[0])
        {
            dp[1] = make_pair(2, (nums[1] - nums[0]) > 0?-1:1);
            maxlen = 2;
        }
        else
        {
            dp[1] = make_pair(1, 0);
            maxlen = 1;
        }
        
        for (int i = 2; i<n; i++)
        {
            int j = i-1;
            while (j >= 0)
            {
                if (nums[j] > nums[i] && dp[j].second != 1 && dp[j].first + 1 > dp[i].first)
                {
                    dp[i] = make_pair(dp[j].first + 1, 1);
                    maxlen = max(maxlen, dp[i].first);
                }
                else if (nums[j] < nums[i] && dp[j].second != -1 && dp[j].first + 1 > dp[i].first)
                {
                    dp[i] = make_pair(dp[j].first + 1, -1);
                    maxlen = max(maxlen, dp[i].first);
                }
                else if (nums[j] == nums[i] && dp[j].first + 1 > dp[i].first)
                {
                    dp[i] = make_pair(dp[j].first, dp[j].second);
                }
                j--;
            }
        }
        for (auto i: dp)    cout<<i.first<<","<<i.second<<endl;
        return maxlen;
    }
};

int main()
{
    Solution a;
    vector<int> in({1,17,5,10,13,15,10,5,16,8});
    int out = a.wiggleMaxLength(in);
    cout<<out<<" ";
    return 0;
}