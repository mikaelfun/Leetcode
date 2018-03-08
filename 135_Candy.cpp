/*
not done
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

output[1,2,2] is [1,2,1] = 4
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <map>

using namespace std;
class Solution {
public:
    int slope(int n)
    {
        return (n*(n+1))/2;
    }

    int candy(vector<int> &ratings) {
        if (ratings.size() <= 1 )
        {
            return ratings.size();
        }
        int tot = 0;        // The final amount of candies
        int up = 0;         // Lenght of the last ascending slope
        int down = 0;       // Lenght of the last descending slope
        int oldsign = 0;    // Previous ratings trend (1 = ascending, -1 == descending, 0 = stable) 

        for (int i = 1; i< ratings.size(); i++)
        {
                        // Current ratings trend, same meaning as oldsign
            int newsign = ratings[i] > ratings[i-1] ? 1 : 
                          ratings[i] < ratings[i-1] ? -1 : 0;
                        // We can calculate the contribution of a slope 
                        // when that slope ends and it's not the peak of a mountain,
                        // that's why we have "newsign == 0" and not "newsign <= 0"
            if ((oldsign > 0 && newsign == 0)  ||
                (oldsign < 0  && newsign >= 0) )
                {
                        // The peak of the mountain should have max(up,down)+1
                        // candies, but the end of the mountain is the beginning of
                        // the next sequence, so we don't the candy at the end of 
                        // the mountain
                    tot += slope(up) + slope(down) + std::max(up, down);
                    up = 0;
                    down = 0;
                }

            if(newsign > 0)
                up++;
            if(newsign < 0)
                down++;
                    // Same rating of the previous child?
                    // Take one candy.If you are better then the next child
                    // the descending slope will take that into account, don't worry
            if(newsign == 0)
                tot++;
                
            oldsign = newsign;
        }
        
                    // Final sequence has to be closed
                    // Why +1? Because we don't have a sequence next!
        tot += slope(up) + slope(down) + std::max(up, down) + 1;
        return tot;
    }
};

int main()
{
    Solution mySol;
    vector<int> a;
    for (int z = 20000; z>=1; z--)
    {
        a.push_back(z);
    }
    //mySol.search(a, 4);
    int out = mySol.candy(a);
    cout<<endl;
    cout<<out<<endl;
    return 0;
}