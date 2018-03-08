/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //divide and conquer
        int size = nums.size();
        vector<int> out;
        if (size == 0 ||target<nums[0] || target>nums[size-1])
        {
            out = {-1,-1};
            return out;
        }
        if (size == 1)
        {
            if (nums[0] != target)
            {
                out = {-1,-1};
                return out;
            }
        }
        int m = size / 2;
        
        vector<int> l;
        vector<int> r;
        int i = 0;
        for (i = 0; i<m; i++)
        {
            l.push_back(nums[i]);
        }
        for (; i<size; i++)
        {
            r.push_back(nums[i]);
        }
        if (nums[m] > target)
        {
            return searchRange(l, target);
        }
        else if (nums[m] < target)
        {
            vector<int> temp = searchRange(r, target);
            if (temp[0] == temp[1] && temp[0] == -1)
            {
                return temp;
            }
            temp[0]+=m;
            temp[1]+=m;
            return temp;
        }
        else
        {
            // nums[m] == target
            
            out.push_back(m);
            out.push_back(m);
            int low = m-1;
            int up = m+1;
            while (low>=0 && nums[low] == target)
            {
                out[0] = low;
                low--;
            }
            while (up<size && nums[up] == target)
            {
                out[1] = up;
                up++;
            }
            return out;
        }
    }
};


int main()
{
    Solution mySol;
    vector<int> a = {0,1,2,7};
    //mySol.search(a, 4);
    vector<int> out = mySol.searchRange(a, 6);
    cout<<out[0]<<endl;
    cout<<out[1]<<endl;
    return 0;
}