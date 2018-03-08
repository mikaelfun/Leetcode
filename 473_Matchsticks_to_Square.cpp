/*
Not done

Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        // must have nums more than 4
        if (nums.size() <4)
        {
            return false;
        }
        else if (nums.size() == 4)
        {
            for (int i = 1; i< 4; i++)
            {
                if (nums[i]!=nums[0])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
    
        }
    }
};
int main()
{
    Solution mysol;
    vector<int> a = {1,1,2,2,2};
    cout<<mysol.makesquare(a)<<endl;
    return 0;
}