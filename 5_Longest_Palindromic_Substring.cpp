/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Input: "cbbd"

Output: "bb"
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.length();
        if (len == 0) return "";
        if (len == 1) return s;
        int maxlen = 1;
        int start = 0;
        /*
        dp[i][j]: is palindromic from i to j
        dp[i][i] is always true
        */
        vector<vector<int>> dp;
        for (int i = 0; i<len; i++)
        {
            vector<int> temp;
            for (int j = 0; j< len; j++)
            {
                temp.push_back(false);
            }
            dp.push_back(temp);
        }
        for (int j = 0;j<len; j++)
        {
            for (int i = j; i>=0; i--)
            {
                if (i == j)
                {
                    dp[i][j] = true;
                }
                else if (i == j - 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                        if (j-i+1 > maxlen)
                        {
                            maxlen = j - i + 1;
                            start = i;
                        }
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                        if (j-i+1 > maxlen)
                        {
                            maxlen = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
        }
        /*
        for (int i = 0;i<dp.size(); i++)
        {
            for (int j = 0; j<dp[i].size(); j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        cout<<start<<", "<<maxlen<<endl;
        return s.substr(start, maxlen);
    }
};
int main()
{
    Solution mySol;
    string s =  "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";
    cout<<mySol.longestPalindrome(s)<<endl;
    return 0;
}