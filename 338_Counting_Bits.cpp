/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
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
    vector<int> countBits(int num) {
        vector<int> out(num+1);
        out[0] = 0;
        out[1] = 1;
        for (int i = 2; i<=num; i++)
        {
            if (i & 0x1)    //i is odd, last bit is 1, means always 1 more bit than the previous number
            {
                out[i] = out[i-1] + 1;
            }
            else
            {
                out[i] = out[i>>1]; // has the same number of bits as i/2
            }
        }
        return out;
    }
};

int main()
{
    Solution a;
    vector<int> out = a.countBits(5);
    for (auto i: out) cout<<i<<" ";
    return 0;
}