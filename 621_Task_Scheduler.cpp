/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //greedy: chars do not matter, take as a list of frequences
        // current biggest frequence pending should be dealt with as soon as cool down is 0
        // else just goes from high to low frequencies
        sort(tasks.begin(), tasks.end());
        int map[26]{0};
        for (int i = 0; i<26;i++)
        {
            map[i] = 0;
        }
        for (char c: tasks)
            map[c - 'A']++;
        sort(map, map + 26);
        int interval = 0;
        while (map[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (map[25] == 0)
                    break;
                if (i < 26 && map[25 - i] > 0)
                    map[25 - i]--;
                interval++;
                i++;
            }
            sort(map, map + 26);
        }
        return interval;
        
    }
    template<class T, typename U>
    T myFunc(T a, U b)
    {
        return (a>b)?a:b;
    }
};


int main()
{
    Solution mySol;
    vector<char> tasks{'A','A','A','A','A','A','B','C','D','E','F','G'};
    // A__A__A__A__A__A
    int n = 2;
    cout<<mySol.leastInterval(tasks, n)<<endl;
    //cout<<mySol.myFunc(4, 3)<<endl;
    return 0;
}