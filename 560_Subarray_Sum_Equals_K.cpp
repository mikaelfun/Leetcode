#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i< nums.size(); i++)
        {
            int sum = nums[i];
            if (sum == k)
            {
                result++;
            }
            for (int j = i+1; j<nums.size(); j++)
            {
                if (sum + nums[j] != k)
                {
                    sum+=nums[j];
                }
                else
                {
                    sum+=nums[j];
                    result++;
                }
            }
        }
        return result;
    }
};
int main()
{
    Solution mysol;
    vector<int> a = {1,1,1};
    cout<<mysol.subarraySum(a, 2)<<endl;
    return 0;
}