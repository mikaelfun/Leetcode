/*
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the senate wants to make a decision about a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: 
A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: 
If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and make the decision about the change in the game.
Given a string representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party respectively. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party, you need to predict which party will finally announce the victory and make the change in the Dota2 game. The output should be Radiant or Dire.

Example 1:
Input: "RD"
Output: "Radiant"
Explanation: The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights any more since his right has been banned. 
And in the round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
Example 2:
Input: "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in the round 1. 
And in the round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
Note:
The length of the given string will in the range [1, 10,000].
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool muteFirstDire(string senate, vector<bool> &status, int index)
    {
        int n = status.size();
        for (int i = 0; i<n;i++)
        {
            if (senate[(i+index) % n] == 'D' && status[(i+index) % n] == true)
            {
                status[(i+index) % n] = false;
                return true;
            }
        }
        return false;
    }
    bool muteFirstRadiant(string senate, vector<bool> &status, int index)
    {
        int n = status.size();
        for (int i = 0; i<n;i++)
        {
            if (senate[(i+index) % n] == 'R' && status[(i+index) % n] == true)
            {
                status[(i+index) % n] = false;
                return true;
            }
        }
        return false;
    }
    string predictPartyVictory(string senate) {
        // RDRRDRDDD
        int rCount = 0, dCount = 0;
        int n = senate.size();
        if (n == 0) return "Dire";
        if (n == 1) return (senate == "R")?"Radiant": "Dire";
        int i = 0;
        vector<bool> status(n);
        for (int m =0; m<n;m++)
        {
            status[m] = true;
        }
        while (true)
        {
            if (senate[i] == 'R')
            {
                if (status[i])
                {
                    if (muteFirstDire(senate, status, i))
                    {
                        //unmuteFirstRadiant(senate, status, i);
                        rCount = 0;
                    }
                    else return "Radiant";
                }
                else 
                {
                    rCount++;
                }
                dCount++;
            }
            else if (senate[i] == 'D')
            {
                if (status[i])
                {
                    if (muteFirstRadiant(senate, status, i))
                    {
                        //unmuteFirstRadiant(senate, status, i);
                        dCount = 0;
                    }
                    else return "Dire";
                }
                else 
                {
                    dCount++;
                }
                rCount++;
            }
            i = (i+1)%n;
            
            // for (bool j: status)
            // {
            //     cout<<j<<endl;
            // }
            // cout<<endl;
            
        }
    }
};

int main()
{
    Solution mySol;
    string senate = "RRR";
    cout<<mySol.predictPartyVictory(senate)<<endl;
    return 0;
}