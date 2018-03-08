/*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, 
say (a1, b1), (a2, b2), ..., (an, bn) 
which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

Solution:
sort the array,
pair them from low to high
lower of every two numbers must be summed, so make sure the other number in the pair is
as closest as to the lower number

in python just use sort, should be easier


*/
#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    //time limit exceeds
    void bubblesort(vector<int>& nums)
    {
        bool sortdone = false;
        int size = nums.size();
        while (!sortdone)
        {
            bool nosort = true;
            for (int i = 0; i < size - 1; i++)
            {
                if (nums[i] > nums[i+1])
                {
                    int temp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = temp;
                    nosort = false;
                }
            }
            if (nosort)
            {
                sortdone = true;
            }
        }
    }
    //mergesort, nlogn
    vector<int> merge(vector<int> l, vector<int>r)
    {
        vector<int> output;
        int k = 0;
        int j = 0;
        while (k < l.size() || j < r.size())
        {
            if (k == l.size())
            {
                output.push_back(r[j]);
                j++;
            }
            else if (j == r.size())
            {
                output.push_back(l[k]);
                k++;
            }
            else if (l[k] < r[j])
            {
                output.push_back(l[k]);
                k++;
            }
            else if (l[k] > r[j])
            {
                output.push_back(r[j]);
                j++;
            }
            else
            {
                output.push_back(r[j]);
                output.push_back(l[k]);
                k++;
                j++;
            }
        }
        return output;
    }
    void mergesort(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 1 || size == 0)
        {
            return;
        }
        if (size == 2)
        {
            if (nums[0] > nums[1])
            {
                int temp = nums[1];
                nums[1] = nums[0];
                nums[0] = temp;
                return;
            }
        }
        else
        {
            vector<int> l,r;
            int i = 0;
            for (i = 0; i< size/2; i++)
            {
                l.push_back(nums[i]);
            }
            for (;i<size;i++)
            {
                r.push_back(nums[i]);
            }
            mergesort(l);
            mergesort(r);
            nums = merge(l,r);
            return;
        }
    }
    //since n is fixed in -10000,10000, we can use hashtable to achieve O(n)
    //use nums[i] as index to store count in hashtable of size 20001
    int arrayPairSum(vector<int>& nums) {
        int size = nums.size();
        int output = 0;
        //using bubble sort
        mergesort(nums);
        //print sorted array
        for (int j = 0; j<size-1; j+=2)
        {
            //cout<<nums[j]<<", "<<nums[j+1]<<endl;
            output += nums[j];
        }
        return output;
        
    }
};
int main()
{
    Solution mySol;
    vector<int> nums = {1,2,3,2};
    cout<<mySol.arrayPairSum(nums)<<endl;
    return 0;
}