#include <iostream>
#include <stack>
#include <cstring>
#include <map>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        stack<string> temp;
        int l = 0;
        int r = 0;
        for (int i = 0; i< s.size();i++)
        {
            r = i;
            if (s.at(i) == ' ')
            {
                if (l != r)
                {
                    temp.push(s.substr(l, r-l));
                } 
                l = i+1;
                continue;
            }
            if (i == s.size()-1 && s.at(i) != ' ')
            {
                temp.push(s.substr(l));
                break;
            }
        }
        string out ="";
        while (temp.size()!=0)
        {
            out.append(temp.top());
            out.append(" ");
            temp.pop();
        }
        out = out.substr(0,out.size()-1);
        s = out;
        
    }
    void reverseWords2(string &s) {
        stack<string> temp;
        string out ="";
        char* m = (char*)s.c_str();
        char d = ' ';
        while (m)
        {
            temp.push((string)strsep(&m, &d));
        }
        while (temp.size()!=0)
        {
            out.append(temp.top());
            out.append(" ");
            temp.pop();
        }
        out = out.substr(0,out.size()-1);
        s = out;
    }
};
int main()
{
    Solution mySol;
    string s = "my name is kun";
    mySol.reverseWords2(s);
    cout<<s<<endl;
    return 0;
}