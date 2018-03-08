//implementing a+b using bit oper only
#include <stdio.h>
#include <iostream>
using namespace std;
int aPlusb(int a, int b)
{
    int result = 0;
    int tmp = 0;
    tmp = (a & b);
    //cout<<tmp<<endl;
    result = a xor b;
    while (tmp != 0)
    {
        tmp = tmp<<1; // 0011 + 0100 = 0111
        int temp1 = result;
        result = result xor tmp;
        tmp = (temp1 & tmp);
    }
    
    return result;
}

int main()
{
    int a = 3;
    int b = 4;
    // 3 + 4 = 7
    cout<<a<<" + "<<b<<" = "<<aPlusb(a,b)<<endl;
    
    // 3 + 7 = 10
    b = 7;
    cout<<a<<" + "<<b<<" = "<<aPlusb(a,b)<<endl;
    
    // 498 + 372 = 870
    a = 498;
    b = 372;
    cout<<a<<" + "<<b<<" = "<<aPlusb(a,b)<<endl;
    return 0;
}
