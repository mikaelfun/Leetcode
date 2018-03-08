/*
Given a string, find the length of the longest substring without repeating characters.

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int out = 0;
        int len = s.length();
        for (int i = 0; i< len; i++)
        {
            int j = i;
            int tmpout = 0;
            map<char, int> temp;
            while (j< len && temp.count(s.at(j)) == 0 )
            {
                temp.insert(pair <char, int>(s.at(j),1));
                j++;
                tmpout++;
                
            }
            if (tmpout > out)
            {
                out = tmpout;
            }
        }
        return out;
    }
};
int main()
{
    Solution mysol;
    cout<<mysol.lengthOfLongestSubstring("pwwkew")<<endl;
    return 0;
}