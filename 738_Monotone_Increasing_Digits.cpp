/*
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9
Example 2:
Input: N = 1234
Output: 1234
Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int pow(int a, int b)
    {
        if (b == 0) return 1;
        if (b == 1) return a;
        return pow(a, b - 1) * a;
    }
    int monotoneIncreasingDigits(int N) {
        //starting from right, if cur digit< left, cur = 1st pos right(9 if no right), left-=1,
        string s = to_string(N);
        
        int size = s.size();
        for (int i = size-1;i>0;i--)
        {
            if (s[i] < s[i-1])
            {
                s[i-1] = s[i-1] - 1;
                int j = i;
                while (j<size){
                    if (s[j] == '9') break;
                    s[j] = '9';
                    j++;
                }
            }
        }
        int result = atoi(s.c_str());
        return result;
    }
};

int main()
{
    Solution mySol;
    int N = 332;
    cout<<mySol.monotoneIncreasingDigits(N)<<endl;
    return 0;
}