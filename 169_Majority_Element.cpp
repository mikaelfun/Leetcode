#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> result;
        for (int i = 0; i<nums.size(); i++)
        {
            if (result[nums[i]])
            {
                result[nums[i]]++;
            }
            else
            {
                result[nums[i]] = 1;
            }
        }
        map<int, int> :: iterator i= result.begin();
        do
        {
            if (i->second >  nums.size() /2)
            {
                return i->first; 
            }
            i++;
        }
        while (i != result.end());
        return 0;
    }
};
int main()
{
    Solution mysol;
    vector<int> a = {1,1,1};
    cout<<mysol.majorityElement(a)<<endl;
    return 0;
}