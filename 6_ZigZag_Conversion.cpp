#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        //pivot indexes are r*2-2
        string output = "";
        int i = 0;
        if (numRows == 1)   return s;
        while (i < numRows)
        {
            for (int j = i; j<s.length(); j+= (numRows*2-2))
            {
                output+=s[j];
                if (i > 0 && i< numRows-1 && (j + (numRows - 1 - i )*2)  < s.length())
                {
                    output+=s[j + (numRows - 1 - i )*2];
                }
            }
            i+=1;
        }
        //cout<<output<<endl;
        return output;
    }
};

int main()
{
    Solution mySol;
    string a = "PAYPALISHIRING";
    int n = 4;
    cout<<mySol.convert(a, n)<<endl;
    return 0;
}