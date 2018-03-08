/*
Not done

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Input: "cbbd"

Output: "bb"
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.length();
        if (len == 0) return "";
        if (len == 1) return s;
        int maxlen = 1;
        int start = 0;
        //want to start from the middle to account for worst case scenario
        //expanding from the center
        //two cases:
        //1. length is odd
        switch (len %2)
        {
            caes 0:
            
                break;
            default:
            case 1:
            
                break;
        }
        //2. length is even
        for (int i = 0;i<1000; i++)
        {
            for (int j = 0; j< 1000;j++)
            {
                isP[i][j] = -1;    
            }
        }
    }
};
int main()
{
    Solution mySol;
    string s = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";
    cout<<mySol.longestPalindrome(s)<<endl;
    return 0;
}