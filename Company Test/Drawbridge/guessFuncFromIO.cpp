#include <iostream>
#include <string>
#include <vector>

using namespace std;

// input: thiisiisgoodd
// f(input): i i o d
// input2: thiiisiisgoodd
// f(input2): i
// input3: this
// f(input3): t h i s

void func(string input)
{
    int maxRepeatLen = 0;
    if (input.length() == 0)    return;
    char cur = input[0];
    int curRepeatLen = 1;
    vector<int> maxIndex;
    maxIndex.push_back(0);
    for (int i = 1; i< input.length(); i++)
    {
        if (input[i] == cur)
        {
            curRepeatLen ++;
        }
        else
        {
            if (curRepeatLen == maxRepeatLen)
            {
                maxIndex.push_back(i - curRepeatLen);
            }
            else if (curRepeatLen > maxRepeatLen)
            {
                maxIndex = vector<int>{i - curRepeatLen};
            }
            maxRepeatLen = max(maxRepeatLen, curRepeatLen);
            curRepeatLen = 1;
            if (i == input.length() - 1)    break;
            cur = input[i];
        }
    }
    if (curRepeatLen == maxRepeatLen)
    {
        maxIndex.push_back( input.length() - 1);
    }
    // cout<<maxRepeatLen<<endl;
    // for (auto each: maxIndex)  cout<<each<<" ";
    // cout<<endl;
    string out = "";
    for (auto each: maxIndex)
    {
        out += input.substr(each, 1);
        out += " ";
    }
    out = out.substr(0, out.length()-1);
    cout<<out<<endl;
    return;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    func("thiisiiisgoodd");
    func("thiisiisgoodd"); 
    func("this");
    return 0;
}
