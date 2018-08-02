/*
You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time .

Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.

Example1

Input: [1,0,5]

Output: 3

Explanation: 
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
3rd move:    2     1 <-- 3    =>    2     2     2   
Example2

Input: [0,3,0]

Output: 2

Explanation: 
1st move:    0 <-- 3     0    =>    1     2     0    
2nd move:    1     2 --> 0    =>    1     1     1     
Example3

Input: [0,2,0]

Output: -1

Explanation: 
It's impossible to make all the three washing machines have the same number of dresses. 
Note:
The range of n is [1, 10000].
The range of dresses number in a super washing machine is [0, 1e5].
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
    int findMinMoves(vector<int>& machines) {
        // brute force
        int total = 0;
        int n = machines.size();
        if (n == 1) return 0;
        for (auto i: machines)  total+=i;
        if (total == 0) return 0;
        if (total < n || total % n != 0) return -1;
        int target = total/n;
        // how to represent state and how to keep track of visited states
        int move = 0;
        while (true)
        {
            bool flag = false;
            int curSum = 0;
            if (machines[0] > target)
            {
                machines[0]--;
                machines[1]++;
                flag = true;
            }
            curSum+=machines[0];
            for (int i =1; i<n-1; i++ )
            {
                if (curSum + machines[i] < (i+1) * target)
                {
                    // cannot give to right
                    if (curSum < i* target && machines[i] > 0)
                    {
                        machines[i]--;
                        machines[i-1]++;
                        curSum++;
                        flag = true;
                    }
                }
                else if (curSum + machines[i] == (i+1) * target)
                {
                    if (machines[i] > target)
                    {
                        machines[i]--;
                        machines[i-1]++;
                        curSum++;
                        flag = true;
                    }
                }
                else
                {
                    //must give right
                    if (machines[i] > 0)
                    {
                        machines[i]--;
                        machines[i+1]++;
                        flag = true;
                    }
                }
                curSum += machines[i];
            }
            if (machines[n-1] > target)
            {
                machines[n-1]--;
                machines[n-2]++;
                flag = true;
            }
            if (flag)
            {
                move++;
            }
            else
            {
                break;
            }
            //for (auto i: machines)  cout<<i<<" ";
            //cout<<endl;
        }
        return move;
    }
};


int main()
{
    Solution mySol;
    //vector<int> arr = {100000,0,100000,0,100000,0,100000,0,100000,0,100000,0};
    //vector<int> arr = {1, 0, 5};
    //vector<int> arr = {2,4,8,4,2};
    int result = mySol.findMinMoves(arr);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}