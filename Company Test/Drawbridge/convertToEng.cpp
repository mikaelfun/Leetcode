#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given a 32-bit unsigned integer (i.e. a number from 0 to 2^31 -1), return a string representing it as an English word.

Examples:
Input: 115
Output: "one hundred fifteen"

Input: 2543
Output: "two thousand five hundred forty three”

Input: 4000091
Output: "four million ninety one”
*/

int pow(int a, int b)
{
    if (b == 0) return 1;
    if (b == 1) return a;
    return pow(a, b-1) * a;
}
string convertToEngNum(int input)
{
    if (input > 9 || input < 0) return "";
    switch (input)
    {
        case 0:
            return "zero";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        default:
            return "";
    }
}
string convertToEngNumTen(int input)
{
    if (input > 19 || input < 10) return "";
    switch (input)
    {
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eighteen";
        case 19:
            return "nineteen";
        default:
            return "";
    }
}
string convertToEngNum2(int input)
{
    if (input > 9 || input < 0) return "";
    switch (input)
    {
        case 2:
            return "twenty";
        case 3:
            return "thirty";
        case 4:
            return "fourty";
        case 5:
            return "fifty";
        case 6:
            return "sixty";
        case 7:
            return "seventy";
        case 8:
            return "eighty";
        case 9:
            return "ninety";
        default:
            return "";
    }
}
int numOfDigits(int input)
{
    int numOfDigits = 0;
    for (int i = 0; i < 10; i++)
    {
        if (input / pow(10, i) == 0)
        {
            break;
        }
        else
        {
            numOfDigits ++;
        }
    }
    return numOfDigits;
}
string convertToEng(int input)
{
    string output = "";
    if (input == 0) return "zero";
    int len = numOfDigits(input);
    if (len == 1)
    {
        return convertToEngNum(input);
    }
    else if (len > 9)
    {
        string out = convertToEng(input / 1000000000) + " billion";
        if (input-(input/1000000000)*1000000000 != 0)
        {
            out+=" ";
            out+=convertToEng(input-(input/1000000000)*1000000000);
        }
        return out;
    }
    else if (len > 6)
    {
        string out = convertToEng(input / 1000000) + " million";
        if (input-(input/1000000)*1000000 != 0)
        {
            out+=" ";
            out+=convertToEng(input-(input/1000000)*1000000);
        }
        return out;
    }
    else if (len > 3)
    {
        string out = convertToEng(input / 1000) + " thousand";
        if (input-(input/1000)*1000 != 0)
        {
            out+=" ";
            out+=convertToEng(input-(input/1000)*1000);
        }
        return out;
    }
    else if (len > 2)
    {
        string out = convertToEng(input / 100) + " hundred";
        if (input-(input/100)*100 != 0)
        {
            out+=" ";
            out+=convertToEng(input-(input/100)*100);
        }
        return out;
    }
    else if (input < 20 && len == 2)
    {
        return convertToEngNumTen(input);
    }
    else
    {
        string out = convertToEngNum2(input / 10);
        if (input - (input / 10) * 10 != 0)
        {
            out+=" ";
            out+=convertToEng(input - (input / 10) * 10);
        }
        return out;
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int input =400200315;
    //cin>>input;
    cout<<input<<endl;
    string output = convertToEng(input);
    cout<<output<<endl;
    // int max = INT32_MAX;
    // cout<<max<<endl;
    return 0;
}