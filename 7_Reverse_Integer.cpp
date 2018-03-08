/*

Example1: x = 123, return 321
Example2: x = -123, return -321

The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int tenpower(int x)
    {
        if (x == 0) 
        {
            return 1;
        }
        if (x == 1) 
        {
            return 10;
        }
        else 
        {
            return (10*tenpower(x-1));
        }
    }
    int numofDigits(int x)
    {
        int out = 0;
        int y;
        if (x>>31 & 0x1)
        {
            y = -x;
        }
        else
        {
            y = x;
        }
        for (int i = 0;i<10;i++)
        {
            if (y / tenpower(i))
            {
                out++;
            }
        }
        return out;
    
    }
    int Abs(int x)
    {
        int out = ~x+1;
        return x>0 ? x : out;
    }
    int reverse(int x) {
        int signbit = 1 - 2 * (x>>31 & 0x1);// -1 if signed, 1 if unsigned
        //overflow only happens if x has max digits
        //and reverse is bigger than INT_MAX
        int max = ~0 ^ (1<<31);
        //overflowed integer will have less digits than the max digits
        
        //case which will never overflow
        int out = 0;
        int numdigits = numofDigits(x);
        int temp = Abs(x);
        //0x1000000000 will the same abs value, hence negative
        if (temp<0)
        {
            return 0;
        }
        for (int i = 0; i<numdigits; i++)
        {
            int temp2 = temp / tenpower(numdigits - 1 - i);
            if (i == 9)
            {
                if (temp2 > 2)
                {
                    return 0;
                }
                if (out - max + temp2 *  tenpower(i) >0)
                {
                    return 0;
                }
            }
            
            out+= temp / tenpower(numdigits - 1 - i) *  tenpower(i);
            temp-= temp / tenpower(numdigits - 1 - i)*  tenpower(numdigits -1 - i);
        }
        //out+=temp * tenpower(numdigits - 1);
     
        return out*signbit;
        
    }
};
int main()
{
    Solution mysol;
    int max = ~0 ^ (1<<31);
    //cout<<max + 100<<endl;
    cout<<mysol.reverse(-2147483648)<<endl;
    return 0;
}