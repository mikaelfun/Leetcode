#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n<3)
        {
            return true;
        }
        //n is positive, can use logical shift
        if (n & 0x1 == 1)
        {
            //then n must have all odd bits 1
            int x = n;
            int i = 1;
            x = x>>i;
            while (x!=0)
            {
                int temp = x & 0x1 ;
                if (temp != 0)
                {
                    return false;
                }
                x = x>>1;
                temp = x & 0x1;
                if (temp != 1)
                {
                    return false;
                }
                x = x>>1;
            }
            return true;
        }
        else
        {
            //n must have all odd bits 0, even bits 1
            int x = n;
            int i = 1;
            x = x>>i;
            while (x!=0)
            {
                int temp = x & 0x1 ;
                if (temp == 0)
                {
                    return false;
                }
                x = x>>1;
                temp = x & 0x1;
                if (temp != 0)
                {
                    return false;
                }
                x = x>>1;
            }
            return true;
        }
    }
};
int main()
{
    Solution mysol;
    cout<<mysol.hasAlternatingBits(13)<<endl; // 1101
    return 0;
}