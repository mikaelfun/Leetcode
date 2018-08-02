/*
Not Done
*/
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> cpy(nums);
        sort(cpy.begin(), cpy.end());
        vector<int> result;
        vector<int> out;
        
        if (nums.size() == 0)   return out;
        int tempBigest = 0;
        unordered_map<int, bool> access;
        if (cpy[0] == 1)   
        {
            result.push_back(1);
            access[1] = true;
            cpy.erase(cpy.begin());
            tempBigest = 1;
            out = result;
        }
        int cur = 0;
        while (access.size() != nums.size())
        {
            for (auto i: cpy)
            {
                if (cur == 0)
                {
                    if (access.find(i)==access.end())
                    {
                        cur = i;
                        access[i] = true;
                        result.push_back(i);
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    if (i % result[result.size()-1] == 0 && access.find(i)==access.end())
                    {
                        result.push_back(i);
                        access[i] = true;
                    }
                }
            }
            if (result[0] == 1)
            {
                if (result.size() > tempBigest)
                {
                    out = result;
                    tempBigest = result.size();
                    
                }
                result.erase(result.begin()+1, result.end());
            }
            else
            {
                if (result.size() > tempBigest)
                {
                    out = result;
                    tempBigest = result.size();
                }
                result.erase(result.begin(), result.end());
            }
            cur = 0;
        }
        return out;
    }
};

int main()
{
    Solution a;
    vector<int> in({3,4,16,8});
    vector<int> out = a.largestDivisibleSubset(in);
    for (auto i: out) cout<<i<<" ";
    return 0;
}