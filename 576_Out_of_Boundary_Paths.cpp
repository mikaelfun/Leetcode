/*
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

Example 1:
Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

Example 2:
Input:m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

Note:
Once you move the ball out of boundary, you cannot move it back.
The length and height of the grid is in range [1,50].
N is in range [0,50].

*/
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <deque>
using namespace std;
class Solution {
public:
    int abs(int a)
    {
        return a>0?a:-a;
    }
    vector<pair<int, pair<int,int>>> findNeighbors(pair<int, pair<int,int>> cur, int m, int n, int left)
    {
        vector<pair<int,pair<int,int>>> out;
        if (left == 0)  return out;
        for (int i = max(0, cur.second.first - left); i< min(m, cur.second.first + left + 1); i++)
        {
            for (int j = max(0, cur.second.second - left); j< min(n, cur.second.second + left + 1); j++)
            {
                if (abs(cur.second.first - i) + abs(cur.second.second - j) < left && (i!=cur.second.first || j!=cur.second.second))
                {
                    out.push_back(make_pair(left - abs(cur.second.first - i) - abs(cur.second.second - j) ,make_pair(i,j)));
                }
            }
        }
        return out;
    }
    //BFS  (i,j) is the state ... wrong!! must use dp
    int findPaths1(int m, int n, int N, int i, int j) {
        deque<pair<int, pair<int,int>>> myQ;
        bool hashT[m][n][N+1];
        memset(hashT, false, m*n*(N+1));
        myQ.push_back(make_pair(N,make_pair(i,j)));
        hashT[i][j][N] == true;
        int path = 0;
        while (myQ.size() > 0)
        {
            auto cur = myQ.front();
            myQ.pop_front();
            if (cur.first == 0) continue;
            if (cur.second.first == 0)
            {
                path = (path+1) % 1000000007;
            }
            if (cur.second.first == m-1)
            {
                path = (path+1) % 1000000007;
            }
            if (cur.second.second == 0 )
            {
                path = (path+1) % 1000000007;
            }
            if (cur.second.second == n-1)
            {
                path = (path+1) % 1000000007;
            }
            for (auto k: findNeighbors(cur, m, n, cur.first))
            {
                //if (hashT[k.second.first][k.second.second][k.first] == false)
                //{
                myQ.push_back(k);
                hashT[k.second.first][k.second.second][k.first] = true;
                //}
            }    
        }
        return path;
    }
    //recursion with memo, time exceeded
    int rec(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& memo)
    {
        if (N == 0) return 0;
        if (memo[i][j][N] > 0)  return memo[i][j][N];
        if (i >= m || j >= n || i<0 ||j <0) return 0;
        int path = 0;
        if (i == 0)
        {
            path++;
        }
        if (i == m-1)
        {
            path++;
        }
        if (j == 0 )
        {
            path++;
        }
        if (j == n-1)
        {
            path++;
        }
        if (N == 1) 
        {
            memo[i][j][N] = path;
            return path;
        }
        for (int a = max(0, i-1); a<min(m, i+2); a++)
        {
            for (int b = max(0, j-1); b<min(n, j+2); b++)
            {
                if ((a == i || b == j) && (a!=i || b != j))
                {
                    path += rec(m, n, N-1, a, b, memo);
                    path %=1000000007;
                }
            }
        }
        path %=1000000007;
        memo[i][j][N] = path;
        return path;
    }
    int findPaths2(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n,vector<int>(N+1, 0)));
        int result = rec(m,n,N,i,j,memo);
        return result;
    }
    int onEdge(int m, int n,  int i, int j)
    {
        int out = 0;
        if (i == 0)
        {
            out++;
        }
        if (i == m-1)
        {
            out++;
        }
        if (j == 0 )
        {
            out++;
        }
        if (j == n-1)
        {
            out++;
        } 
        return out;
    }
    //dp[i][j][n] number of was out at i, j with n steps left
    int findPaths(int m, int n, int N, int i, int j) {
        int dp[m][n][N+1];
        memset(dp, 0, sizeof(int) * m*n*(N+1));
        if (N == 0) return 0;
        if (N == 1) return onEdge(m,n,i,j);
        for (int b = 0; b < m; b++)
        {
            dp[b][0][1] ++;
            dp[b][n-1][1] ++;
        }
        for (int c = 0; c<n; c++)
        {
            dp[0][c][1] ++;
            dp[m-1][c][1] ++;
        }
        for (int a = 2; a < N+1; a++)
        {
            for (int b = 0; b < m; b++)
            {
                for (int c = 0; c<n; c++)
                {
                    dp[b][c][a]+=onEdge(m,n,b,c);
                    dp[b][c][a] %=1000000007;
                    if (b>=1)
                    {
                        dp[b][c][a]+=dp[b-1][c][a-1];
                        dp[b][c][a] %=1000000007;
                    }
                    if (b<m-1){
                        dp[b][c][a]+=dp[b+1][c][a-1];
                        dp[b][c][a] %=1000000007;
                    }
                    if (c>=1){
                        dp[b][c][a]+=dp[b][c-1][a-1];
                        dp[b][c][a] %=1000000007;
                    }
                    if (c<n-1){
                        dp[b][c][a]+=dp[b][c+1][a-1];
                        dp[b][c][a] %=1000000007;
                    }
                }
            }
        }
        return dp[i][j][N];
    }
};



int main()
{
    Solution mySol;


    int result = mySol.findPaths(50,50,50,25,25);
    cout<<result<<endl;


    return 0;
}