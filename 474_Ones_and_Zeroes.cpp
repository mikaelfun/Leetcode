/*
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;
bool sortByLength(string a, string b){return a.size() < b.size();}
class Solution {
public:
    int countOne(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                count ++;
            }
        }
        return count;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // assume that sorting string will put shorter strings first
        sort(strs.begin(), strs.end(), sortByLength); // greedy doesnt work
        // for (string s: strs)
        // {
        //     cout<<s<<" ";
        // }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); // num of strings ending at i, 0s left, 1s left
        vector<pair<int, int>> pairs;
        int maxPair = 1;
        for (int i = 0; i< strs.size(); i++)
        {
            int oneCount = countOne(strs[i]);
            int zeroCount = strs[i].length() - oneCount;
            if (zeroCount <= m && oneCount <= n)
            {
                dp[zeroCount][oneCount] =  1;
                pairs.push_back(make_pair(zeroCount, oneCount));
            }
        }
        for (int i = 0; i< strs.size(); i++)
        {
            for (int j = i+1; j< strs.size(); j++)
            {
                if (pairs[i].first + pairs[j].first <= m && pairs[i].second + pairs[j].second <= n)
                {
                    dp[pairs[i].first + pairs[j].first][pairs[i].second + pairs[j].second] = max(dp[pairs[i].first + pairs[j].first][pairs[i].second + pairs[j].second], dp[pairs[i].first][pairs[i].second] + dp[pairs[j].first][pairs[j].second]);
                }
                
            }
        }
        for (auto i: dp)
        {
            for (auto j:i)
                cout<<j<<" ";
            cout<<endl;
        }
        return dp[m][n];
    }
};
int main()
{
    Solution mySol;
    vector<string> strs{"10","0","1"};
    

    //"11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01"};
    int m = 1;
    int n = 1;
    int result = mySol.findMaxForm(strs, m, n);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}