/*
Implement atoi to convert a string to an integer.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
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
    bool isDigit(char s)
    {
        return (s-'0' >=0 && s-'0' < 10);
    }
    int myAtoi(string str) {
        int max = ~0 ^ (1<<31);
        int min = 1<<31;
        int numofdigits = 0;
        int out = 0;
        int i = 0;
        if (str.length() == 0)
        {
            return 0;
        }
        //get rid of spaces at beginning
        while (' ' == str.at(i) && i<str.length())
        {
            i++;
        }
        if (str.at(i) == '-' || str.at(i) == '+')
        {
            int sign = (str.at(i) == '-') ? -1:1;
            int power = 0;
            int j = i+1;
            for (int k = j; k<str.length();k++)
            {
                if (isDigit(str.at(k)))
                {
                    numofdigits++;
                }
                else
                {
                    break;
                }
            }
            if (numofdigits == 0)
            {
                return 0;
            }
            if (numofdigits > 10)
            {
                return (sign == 1)? max : min;
            }
            while (power<numofdigits)
            {
                if (power == 9)
                {
                    if (sign == 1)
                    {
                        //overflow for pos
                        if (out - max + (str.at(j) - 48)*tenpower(numofdigits - power - 1) > 0)
                        {
                            return max;
                        }
                    }
                    else
                    {
                        if (out - max + (str.at(j) - 48)*tenpower(numofdigits - power - 1) == 1)
                        {
                            return min;
                        }
                        if (out - max + (str.at(j) - 48)*tenpower(numofdigits - power - 1) > 1)
                        {
                            return min;
                        }
                    }
                }
                out+= (str.at(j) - 48)*tenpower(numofdigits - power - 1);
                power++;
                j++;
            }
            out*=sign;
        }
        else if (0 <= str.at(i) - '0' && str.at(i) - '0' < 10)
        {
            int power = 0;
            int j = i;
            for (int k = j; k<str.length();k++)
            {
                if (isDigit(str.at(k)))
                {
                    numofdigits++;
                }
                else
                {
                    break;
                }
            }
            if (numofdigits == 0)
            {
                return 0;
            }
            if (numofdigits > 10)
            {
                return max;
            }
            while (power<numofdigits)
            {
                if (power == 9)
                {
                    //overflow for pos
                    if (out - max + (str.at(j) - 48)*tenpower(numofdigits - power - 1) > 0)
                    {
                        return max;
                    }
                
                }
                out+= (str.at(j) - 48)*tenpower(numofdigits - power - 1);
                power++;
                j++;
            }
        }
        else
        {
            return 0;
        }
        
    //    cout<<str<<endl; 
        return out;
    }
};
int main()
{
    Solution mysol;
    int min = 1<<31;
    cout<<mysol.myAtoi("+-2")<<endl;
    return 0;
}