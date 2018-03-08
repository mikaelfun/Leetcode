/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <map>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        while (i<nums.size() && nums[i] > target)
        {
            i++;
        }
        if (i == nums.size())
        {
            return false;
        }
        while (i<nums.size())
        {
            if (nums[i] == target)
            {
                //cout<<nums[i]<<endl;
                //cout<<target<<endl;
                return true;
            }
            if (nums[i] < target)
            {
                i++;
                continue;
            }
            else
            {
                //cout<<"false"<<endl;
                return false;
            }
        }
        //cout<<"false"<<endl;
        return false;
    }
};

int main()
{
    Solution mySol;
    vector<int> a = {4,5,6,7,0,1,2};
    //mySol.search(a, 4);
    cout<<mySol.search(a, 3)<<endl;
    return 0;
}