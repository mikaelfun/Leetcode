/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
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
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<pair<int,int>> LIS(n, make_pair(1,1));  //pair length, numbers
        vector<int> maxIndex;
        int maxlen = 1;
        for (int i = 0 ; i< n; i++)
        {
            for (int j = 0; j<i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (LIS[i].first < LIS[j].first + 1)
                    {
                        LIS[i] = make_pair(LIS[j].first + 1, LIS[j].second);
                    }
                    else if (LIS[i].first == LIS[j].first + 1)
                    {
                        LIS[i].second+= LIS[j].second;
                    }
                }
            }
            if (LIS[i].first == maxlen)
            {
                maxIndex.push_back(i);
            }
            else if (LIS[i].first > maxlen)
            {
                maxIndex.erase(maxIndex.begin(), maxIndex.end());
                maxlen = LIS[i].first;
                maxIndex.push_back(i);
            }
        }
        int count = 0;
        for (auto i: maxIndex)   cout<<i<<" ";
        cout<<endl;
        for (auto i: LIS)   cout<<i.first<<", "<<i.second<<endl;
        if (maxIndex.size() == n)   return n;
        for (auto i: maxIndex)
        {
            count+= LIS[i].second;
        }
        return count;
    }
};
int main()
{
    Solution mySol;
    vector<int> in = {1,2,4,3,5,4,7,2};
    
    int result = mySol.findNumberOfLIS(in);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}