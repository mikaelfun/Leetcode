/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //using hashtable to store 10 letter string and occurence
        unordered_map<string, int> occ;
        vector<string> output;
        if (s.length() <= 10)
        {
            return output;
        }
        for (int i = 0; i<=s.length() - 10;++i)
        {
            string tmp = s.substr(i, 10);
            //cout<<i<<endl;
            if (occ.find(tmp) == occ.end())
            {
                occ[tmp] =1;
            }
            else
            {
                occ[tmp] += 1;
            }
        }
        for (auto i: occ)
        {
            //cout<<i.first<<endl;
            //cout<<i.second<<endl;
            if ((i).second > 1)
            {
                output.push_back((i).first);
            }
        }
        return output;
    }
};

int main()
{
    Solution mySol;
    string n = "AAAAAAAAAAA";
    vector<string> out = mySol.findRepeatedDnaSequences(n);
    for (auto each:out)
    {
        cout<<each<<endl;
    }
    return 0;
}