/*
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

 

Example 1:

Input: [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 

Note:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles) is odd.
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
    // 1st: greedy  wrong
    bool stoneGame1(vector<int>& piles) {
        int n = piles.size();
        int l = 0;
        int r = n - 1;
        int alexSum = 0;
        int leeSum = 0;
        bool alexTurn = true;
        while (l<r)
        {
            if (piles[l] > piles[r])
            {
                if (alexTurn)
                {
                    alexSum+=piles[l];
                    alexTurn = false;
                }
                else
                {
                    leeSum+=piles[l];
                    alexTurn = true;
                }
                l++;
            }
            else
            {
                if (alexTurn)
                {
                    alexSum+=piles[r];
                    alexTurn = false;
                }
                else
                {
                    leeSum+=piles[r];
                    alexTurn = true;
                }
                r--;
            }
        }
        return alexSum>leeSum;
    }
    // 2: recursion time exceeded
    int helper(vector<int>& piles, int l, int r, bool alexTurn)
    {
        if (l == r)     
        {
            return 0;  
        }
        if (l == r-1)
        {
            return max(piles[l], piles[r]);
        }
        if (alexTurn)
        {
            return max(piles[l] + helper(piles, l+1, r, false), piles[r] + helper(piles, l, r-1, false));
        }
        else
        {
            if (piles[l] + helper(piles, l+1, r, false) > piles[r] + helper(piles, l, r-1, false))
            {
                return helper(piles, l+1, r, true);    
            }
            else
            {
                return helper(piles, l, r-1, true);
            }
        }
    }
    bool stoneGame2(vector<int>& piles) {
        int n = piles.size();
        // just 2 piles, alex wins by picking larger pile
        if (n == 2) return true;
        int all = 0;
        for (auto each: piles)  all+=each;
        int alexSum = helper(piles, 0, n-1, true);
        cout<<all<<endl;
        cout<<alexSum<<endl;
        return alexSum > all/2;
    }
    // 3: dp
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // just 2 piles, alex wins by picking larger pile
        if (n == 2) return true;
        pair<int,int> dp[n][n];     // sum of stone from i to j for Alex and Lee
        
        // for (int i = 0; i<n; i++)
        // {
        //     for (int j = 0; j<n; j++)
        //     {
        //         dp[i][j] = make_pair(0,0);
        //     }
        // }
        
        for (int i = 0; i<n; i++)
        {
            for (int j = i-1; j>= 0; j--)
            {
                if (j == i-1)
                {
                    dp[j][i] = make_pair(max(piles[i], piles[j]), min(piles[i], piles[j]));
                }
                else
                {
                    if ((i-j) % 2 == 0) // lee's turn
                    {
                        
                        if (dp[j][i-1].second + piles[i] < dp[j+1][i].second + piles[j])
                        {
                            dp[j][i] = make_pair(dp[j+1][i].first, dp[j+1][i].second + piles[j]);
                        }
                        else
                        {
                            dp[j][i] = make_pair(dp[j][i-1].first, dp[j][i-1].second + piles[i]);
                        }
                    }
                    else    // alex's turn
                    {
                        if (dp[j][i-1].first + piles[i] < dp[j+1][i].first + piles[j])
                        {
                            dp[j][i] = make_pair(dp[j+1][i].first + piles[j], dp[j+1][i].second);
                        }
                        else
                        {
                            dp[j][i] = make_pair(dp[j][i-1].first + piles[i], dp[j][i-1].second);
                        }
                    }
                }
            }
        }
        return dp[0][n-1].first > dp[0][n-1].second;
    }
};

int main()
{
    Solution mySol;
    vector<int> arr = {7,7,12,16,41,48,41,48,11,9,34,2,44,30,27,12,11,39,31,8,23,11,47,25,15,23,4,17,11,50,16,50,38,34,48,27,16,24,22,48,50,10,26,27,9,43,13,42,46,24};

    
    bool result = mySol.stoneGame(arr);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}
