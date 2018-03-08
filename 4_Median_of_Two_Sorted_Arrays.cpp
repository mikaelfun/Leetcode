/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double out = 0;
        //if sum of two list size is odd, we find the median of the combined list.
        //if sum of two list size is even, we find the average of the two medians of the combined list.
        int sumofSize = nums1.size() + nums2.size();
        vector<int> combined;
        if (sumofSize % 2 == 1)
        {
            for (int i = 0; i< (sumofSize+1)/2; i++)
            {
                if (nums1.size() == 0)
                {
                    combined.push_back(*nums2.begin());
                    nums2.erase(nums2.begin());
                }
                else if (nums2.size() == 0)
                {
                    combined.push_back(*nums1.begin());
                    nums1.erase(nums1.begin());
                }
                else if (*nums1.begin() < *nums2.begin())
                {
                    combined.push_back(*nums1.begin());
                    nums1.erase(nums1.begin());
                }
                else
                {
                    combined.push_back(*nums2.begin());
                    nums2.erase(nums2.begin());
                }
            }
            int x = *(combined.begin() + (sumofSize-1)/2);
            out = x * 1.0;
            
        }
        else
        {
            for (int i = 0; i< (sumofSize)/2 + 1; i++)
            {
                if (nums1.size() == 0)
                {
                    combined.push_back(*nums2.begin());
                    nums2.erase(nums2.begin());
                }
                else if (nums2.size() == 0)
                {
                    combined.push_back(*nums1.begin());
                    nums1.erase(nums1.begin());
                }
                else if (*nums1.begin() < *nums2.begin())
                {
                    combined.push_back(*nums1.begin());
                    nums1.erase(nums1.begin());
                }
                else
                {
                    combined.push_back(*nums2.begin());
                    nums2.erase(nums2.begin());
                }
            }
            out = (*(combined.begin()+sumofSize/2)  + *(combined.begin()+sumofSize/2 - 1))/2.0;
            
        }
        return out;
    }
};
int main()
{
    Solution mySol;
    vector<int> nums1;
    nums1.push_back(12);
    nums1.push_back(73);
    nums1.push_back(131);
    nums1.push_back(152);
    vector<int> nums2 = {1,2,3};

    cout<<mySol.findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}