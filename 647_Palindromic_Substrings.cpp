/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n <= 1) return n;
        int count = n;
        for (int i = 0; i< n - 1; i++)
        {
            int r = i + 1;
            int l = i;
            while (l >= 0 && r <n)
            {
                if (s[l] == s[r])
                {
                    count++;
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            if (i > 0)
            {
                l = i - 1;
                r = i + 1;
                while (l >= 0 && r < n)
                {
                    if (s[l] == s[r])
                    {
                        count++;
                        l--;
                        r++;
                    }
                    else break;
                }
            }
            
        }
        return count;
    }
};
int main()
{
    Solution mySol;
    string in = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    
    int result = mySol.countSubstrings(in);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}