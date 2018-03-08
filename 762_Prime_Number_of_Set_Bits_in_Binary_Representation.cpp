/*

Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)

Note:

L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int twoPower[20];
    int power(int x, int y)
    {
        if (y == 0)
        {
            return 1;
        }
        if (y == 1)
        {
            return x;
        }
        if (y == 2)
        {
            return x*x;
        }
        return x*power(x, y-1);
    }
    void initializeTwoPower()
    {
        for (int i = 0; i< 20; i++)
        {
            twoPower[i] = 0;
        }
        twoPower[0] = 1;
        for (int i = 1; i< 20; i++)
        {
            twoPower[i] = twoPower[i-1] * 2;
        }
        return;
        
    }
    int countPrimeSetBits(int L, int R) {
        initializeTwoPower();
        int count = 0;
        for (int i = L; i<=R; i++)
        {
            if (PrimeSet(i))
            {
                count++;
            }
        }
        return count;
    }
    bool PrimeSet(int i)
    {
        int j = 0;
        for (; j<20; j++)
        {
            if (i / twoPower[j] == 0)
            {
                j--;
                break;
            }
        }
        if (j == 20)
        {
            j--;
        }
        int temp = i;
        int count = 0;
        for (int k = j; k >= 0; k--)
        {
            if (temp > twoPower[k])
            {
                temp-=twoPower[k];
                count++;
            }
            else if (temp == twoPower[k])
            {
                count++;
                break;
            }
            else
            {
                continue;
            }
        }
        if (isPrime(count))
        {
            return true;
        }
        
        return false;
    }
    bool isPrime(int i)
    {
        if (i == 0 || i == 1)
        {
            return false;
        }
        if (i == 2 || i == 3)
        {
            return true;
        }
        if ((i>>1)<<1 == i)
        {
            return false;
        }
        for (int j = 2; j<=i/2; j++)
        {
            if (i % j == 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution mysol;
    cout<<mysol.countPrimeSetBits(940962,941236)<<endl; 
    return 0;
}