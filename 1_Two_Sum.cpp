/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    //brute force, O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i< nums.size();i++)
        {
            for (int j = i+1; j<nums.size();j++)
            {
                if (nums.at(i)+nums.at(j) == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
    //hashmap O(n)
    vector<int> twoSumMap(vector<int>& nums, int target) 
    {
        vector<int> result;
        map<int, int> table;
        for (int k = 0; k<nums.size();k++)
        {
            table[target - nums.at(k)] = k;
        }
        for (int i = 0; i< nums.size();i++)
        {
            if (table.find(nums.at(i)) != table.end() && table[nums.at(i)] != i) //in case that it adds the same number twice.
            {
                result.push_back(i);
                result.push_back(table[nums.at(i)]);
                return result;
            }
        }
        return result;
    }
};

int main()
{
    Solution mySol;
    vector<int> nums;
    nums.push_back(12);
    nums.push_back(73);
    nums.push_back(11);
    nums.push_back(15);
    int target = 88;
    vector<int> result = mySol.twoSum(nums, target);
    for (int i = 0; i<result.size();i++)
    {
        cout<<result.at(i)<<" ,";
    }
    cout<<endl;
    
    
    vector<int> result1 = mySol.twoSumMap(nums, target);
    for (int i = 0; i<result1.size();i++)
    {
        cout<<result1.at(i)<<" ,";
    }
    cout<<endl;
    return 0;
}