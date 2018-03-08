/*
Given a sorted array consisting of only integers where every element appears twice except for 
one element which appears once. Find this single element that appears only once.
Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> myMap;
        for (int i = 0 ; i<nums.size(); i++)
        {
            if (myMap[nums[i]])
            {
                myMap[nums[i]]++;
            }
            else
            {
                myMap[nums[i]] = 1;
            }
        }
        for (int j = 0; j<nums.size();j++)
        {
            if (myMap[nums[j]] == 1)
            {
                return nums[j];
            }
        }
        
    }
};

int main()
{
    Solution mySol;
    vector<int> a = {1,1,2,3,3,4,4,8,8};
    cout<<mySol.singleNonDuplicate(a)<<endl;
}