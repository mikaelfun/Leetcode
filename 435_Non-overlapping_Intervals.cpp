/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

/**
 * Definition for an interval.
 *  */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool sortByending(Interval a, Interval b)
{
    return (a.end < b.end);
}
int max(int a, int b){return a>b?a:b;}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        //sort based on ending time, simpler, based on greedy, find first nonoverlapping interval
        int maxInterval = 1;
        int allInterval = intervals.size();
        if (allInterval == 0 || allInterval == 1)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), sortByending);
        
        int prev = 0;
        for (int i=1; i < allInterval; i++)
        {
            maxIntervalEnding[i] = 1;
            if (intervals[i].start>= intervals[prev].end)
            {
                prev = i;
                maxInterval+=1;
            }
            
        }
        return allInterval - maxInterval;
    }
    
    int eraseOverlapIntervals2(vector<Interval>& intervals) {
        //sort based on ending time, based on dp, calculate the most intervals by ending at i
        int maxInterval = 1;
        int allInterval = intervals.size();
        if (allInterval == 0 || allInterval == 1)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), sortByending);
        vector<int> maxIntervalEnding(allInterval);
        maxIntervalEnding[0] = 1;
        
        
        for (int i=1; i < allInterval; i++)
        {
            maxIntervalEnding[i] = 1;
            int j = i-1;
            while (j>=0)
            {
                if (maxIntervalEnding[i] > j+2)
                {
                    break;
                }
                if (intervals[i].start>= intervals[j].end)
                {
                    maxIntervalEnding[i] = max(maxIntervalEnding[i], maxIntervalEnding[j] + 1);
                    if (maxIntervalEnding[i] > maxInterval)
                    {
                        maxInterval = maxIntervalEnding[i];
                    }
                }
                j--;
            }
            
        }
        for (int i: maxIntervalEnding)
        {
            cout<<i<<endl;
        }
        cout<<maxInterval<<","<<allInterval<<endl;
        return allInterval - maxInterval;
    }
};

int main()
{
    Solution mySol;
    vector<Interval> intervals{Interval(1,2),Interval(1,2),Interval(1,2)};
    cout<<mySol.eraseOverlapIntervals(intervals)<<endl;
    return 0;
}