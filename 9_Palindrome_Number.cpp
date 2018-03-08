/*
Determine whether an integer is a palindrome
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int abs(int x)
    {
        return (x>0)?x:-x;
    }
    bool isPalindrome(int x) {
        //we can convert it to string and find out if it's palindromic
        string s = "";
        //cannot get abs for MIN
        if (x == 1<<31)
        {
            return false;
        }
        s = to_string(x);
        //cout<<s<<endl;
        int len = s.length();
        if (len == 0)
        {
            return false;
        }
        int i = 0;
        if (len == 0)
        {
            return false;
        }
        if (len == 1)
        {
            return true;
        }
        while (i<(len)/2 + 1)
        {
            if (s.at(i) == s.at(len-i-1))
            {
                i++;
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution mysol;
    cout<<mysol.isPalindrome(-12321)<<endl;
    return 0;
}