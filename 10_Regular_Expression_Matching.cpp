/*
Not done
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool matches(string s, string p, int i, int j)
    {
        int lenS = s.length();
        int lenP = p.length();
        if (i<0 || j<0)
        {
            return false;
        }
        if (i>=lenS || j>=lenP)
        {
            return false;
        }
        if (s.at(i) == p.at(j))
        {
            return true;
        }
        else if (p.at(j) == '.')
        {
            return true;
        }
        else if (p.at(j) == '*' && i>0 && j>0 && s.at(i-1) == p.at(j-1))
        {
            return true;
        }
        else if (p.at(j) == '*' && p.at(j-1) == '.' && i>0 && j>1 && s.at(i-1) == p.at(j-2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int lenS = s.length();
        int lenP = p.length();
        bool dotStarFlag = false;
        if (lenS == 0)
        {
           return true;
        }
        if (lenP == 0)
        {
           return false;
        }
        vector<vector<bool>> match(lenS, vector<bool>(lenP, false));
        for (int i = lenS-1; i>=0;i--)
        {
            for (int j = lenP - 1; j>=0; j--)
            {
                if (i<lenS - 1 && match[i+1][j] && j>0)
                {
                    match[i][j-1] = matches(s,p,i,j);
                }
                else if (j<lenP - 1 && match[i][j + 1])
                {
                    match[i][j] = true;
                }
                else if (lenS - i == lenP - j && s.at(i) == p.at(j))
                {
                    match[i][j] = true;
                }
                else if (matches(s,p,i,j))
                {
                    match[i][j] = true;
                }
                else if (p.at(j) == '*' && j>0 && p.at(j-1) == s.at(i))
                {
                    match[i][j] = true;
                }
                else if (p.at(j) == '*' && j>0 && p.at(j-1) == '.' && i>0 && s.at(i) == s.at(i-1))
                {
                    match[i][j] = true;
                }
                else
                {
                    continue;
                }
            }
        }
        for (int k = 0; k<lenP;k++)
        {
            if (match[0][k])
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution mysol;
    cout<<mysol.isMatch("aab","c*a*b")<<endl;
    cout<<mysol.isMatch("aaa","aa")<<endl;
    cout<<mysol.isMatch("ab",".*c")<<endl;
    return 0;
}