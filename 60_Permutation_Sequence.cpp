/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int fact(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        return n*fact(n-1);
    }
    string getPermutation(int n, int k) {
        int max = fact(n);
        int temp = k;
        if (n>9 || n<1 || k > max || k < 1)
        {
            return "";
        }
        
        string out = "";
        int i = 1;
        for (int j = 0; j<n; j++)
        {
            for (;i<=n;i++)
            {
                if (max/n* i > temp)
                {
                    out.append(to_string(i));
                    temp = temp - max/n* (i-1);
                    break;
                }
            }
        }
        return out;
    }
};

int main()
{
    Solution mySol;
    cout<<mySol.getPermutation(3,3)<<endl;
        
    return 0;
}