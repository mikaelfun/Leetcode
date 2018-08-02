/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //find the first bigger cookie for each child starting from the most greedy
        //time performance a lot better
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        int i = 0, j = 0;
        while (i<g.size() && j<s.size())
        {
            if (s[j] >= g[i])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
    int findContentChildren2(vector<int>& g, vector<int>& s) {
        //find the first bigger cookie for each child starting from the most greedy
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        for (int i = g.size() - 1; i>=0; i--)
        {
            for (int j = 0; j<s.size(); j++)
            {
                if (s[j] >= g[i])
                {
                    count++;
                    s.erase(s.begin()+j);
                    if (s.size() == 0)
                    {
                        return count;
                    }
                    break;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution mySol;
    vector<int> g{3,1,2};
    vector<int> s{1,2};
    cout<<mySol.findContentChildren(g,s)<<endl;
    return 0;
}