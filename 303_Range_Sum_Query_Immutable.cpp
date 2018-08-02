/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
class NumArray {
public:
    NumArray(vector<int> nums) {
        sumEnding.push_back(0);
        if (nums.size() > 0)
        {
            sumEnding.push_back(nums[0]);
        }
        for (int i = 1; i<nums.size(); i++)
        {
            sumEnding.push_back(sumEnding[sumEnding.size() - 1] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return sumEnding[j+1] - sumEnding[i];
    }
    vector<int> sumEnding;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
 
 
int main()
{
    vector<int> nums({-2, 0, 3, -5, 2, -1});
    NumArray obj = NumArray(nums);
    int param_1 = obj.sumRange(2,3);
    cout<<param_1<<endl;
    return 0;
}