/*
A sequence X_1, X_2, ..., X_n is fibonacci-like if:

n >= 3
X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.

(Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)

 

Example 1:

Input: [1,2,3,4,5,6,7,8]
Output: 5
Explanation:
The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: [1,3,7,11,12,14,18]
Output: 3
Explanation:
The longest subsequence that is fibonacci-like:
[1,11,12], [3,11,14] or [7,11,18].
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 1. dp
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        if (n < 3)  return 0;
        unordered_map<int, int> hash;   //number and its index
        int maxNum = A[n-1];
        int lenLon = 0;
        for (auto index = 0; index<n; index++)  hash[A[index]] = index;
        int dp[n][n]; //length of max subseq using base i, j   top down
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                dp[i][j] = 0;
            }
        }
        // for (int i = n-3; i>=0; i--)
        // {
        //     for (int j = i+1; j<n-1; j++)
        //     {
        //         if (A[i] + A[j] > maxNum)   break;
        //         //if (n-j < lenLon - 1)       break;
        //         if (hash[A[i] + A[j]])
        //         {
        //             if (dp[j][hash[A[i] + A[j]]] > 0)
        //             {
        //                 dp[i][j] = dp[j][hash[A[i] + A[j]]] + 1;
        //             }
        //             else
        //             {
        //                 dp[i][j] = 3;
        //             }
        //             lenLon = max(dp[i][j], lenLon);
        //         }
        //     }
        // }
        for (int i = 2; i<n; i++)
        {
            for (int j = 1; j<i; j++)
            {
                if (A[i] - A[j] < A[0]) break;
                bool a = (A[i] - A[j] < A[j]);
                bool b = hash.find(A[i] - A[j]) != hash.end();
                
                if (a && b)
                {
                    if (dp[hash[A[i] - A[j]]][j] >= 3)
                    {
                        dp[j][i] = dp[hash[A[i] - A[j]]][j] + 1;
                    }
                    else
                    {
                        dp[j][i] = 3;
                    }
                    lenLon = max(dp[j][i], lenLon);
                }
            }
        }
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return lenLon;
        
    }
};

int main() {
    vector<int> input{1,2,3,4,5,6,7,8};
    Solution a;
    int output = a.lenLongestFibSubseq(input);
    cout<<output<<endl;
    return 0;
}