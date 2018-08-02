/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    // 1st: recursion   time exceeded
    vector<vector<string>> helper(string& s, int l, unordered_set<string>& hash)
    {
        int n = s.length();
        vector<vector<string>> out;
        if (l == n) return out;
        for (int i = l; i < n; i++)
        {
            if (hash.find(s.substr(l, i-l+1))!=hash.end())
            {
                if (i == n-1)
                {
                    out.push_back(vector<string>{s.substr(l, i-l+1)});
                    return out;
                }
                //cout<<s.substr(l, i-l+1)<<endl;
                vector<vector<string>> tmp = helper(s, i+1, hash);
                for (int j = 0; j<tmp.size(); j++)
                {
                    //for (auto k: tmp[j])    cout<<k<<" ";
                    //cout<<endl;
                    tmp[j].insert(tmp[j].begin(), s.substr(l, i-l+1));
                    out.push_back(tmp[j]);
                }
            }
        }
        return out;
    }
    // 1st: recursion   memo, passed
    vector<vector<string>> helper2(string& s, int l, unordered_set<string>& hash, vector<vector<vector<string>>>& memo, vector<bool>& stored)
    {
        int n = s.length();
        vector<vector<string>> out;
        if (l == n) return out;
        if (stored[l])
        {
            cout<<"found: "<<l<<endl;
            return memo[l];
        }
        for (int i = l; i < n; i++)
        {
            if (hash.find(s.substr(l, i-l+1))!=hash.end())
            {
                //cout<<s.substr(l, i-l+1)<<endl;
                if (i == n-1)
                {
                    out.push_back(vector<string>{s.substr(l, i-l+1)});
                    memo[l] = out;
                    stored[l] = true;
                    cout<<"stored: "<<l<<endl;
                    return out;
                }
                //cout<<s.substr(l, i-l+1)<<endl;
                vector<vector<string>> tmp = helper2(s, i+1, hash, memo, stored);
                for (int j = 0; j<tmp.size(); j++)
                {
                    //for (auto k: tmp[j])    cout<<k<<" ";
                    //cout<<endl;
                    tmp[j].insert(tmp[j].begin(), s.substr(l, i-l+1));
                    out.push_back(tmp[j]);
                }
            }
        }
        memo[l] = out;
        stored[l] = true;
        cout<<"stored: "<<l<<endl;
        return out;
    }
    vector<string> wordBreak1(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<string> out;
        unordered_set<string> hash;
        for (auto each: wordDict)   hash.insert(each);
        vector<vector<vector<string>>> memo(n);
        //vector<vector<string>> output = helper(s, 0, hash);
        vector<bool> stored(n, false);
        vector<vector<string>> output = helper2(s, 0, hash, memo, stored);
        for (auto each: output)
        {
            string tmp = "";
            for (auto i : each)
            {
                tmp+=i;
                tmp+=" ";
            }
            tmp=tmp.substr(0, tmp.length() - 1);
            out.push_back(tmp);
        }
        return out;
    }
    // 2nd: dp      memory limit exceeded
    vector<string> wordBreak2(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<string> out;
        unordered_set<string> hash;
        for (auto each: wordDict)   hash.insert(each);
        vector<vector<string>> dp[n];
        unordered_set<int> startIndex;
        for (int i = n- 1; i>=0; i--)
        {
            cout<<"i = "<<i<<endl;
            unordered_set<int> tmp;
            for (auto each: startIndex)
            {
                cout<<each<<" ";
                if (hash.find(s.substr(i, each - i))!=hash.end())
                {
                    for (auto k : dp[each])
                    {
                        k.insert(k.begin(), s.substr(i, each - i));
                        dp[i].push_back(k);
                    }
                    tmp.insert(i);
                }
            }
            for (auto each: tmp)  startIndex.insert(each);  
            cout<<endl;
            if (hash.find(s.substr(i))!=hash.end())
            {
                vector<string> tmp{s.substr(i)};
                dp[i].push_back(tmp);
                startIndex.insert(i);
            }
        }
        // for (int i = n- 1; i>=0; i--)
        // {
        //     cout<<"dp["<<i<<"]"<<endl;
        //     for (auto dd: dp[i])
        //     {
        //         for (string a : dd)
        //         {
        //             cout<<a<<" ";
        //         }
        //         cout<<endl;
        //     }
               
        // }
        for (auto each: dp[0])
        {
            string tmp = "";
            for (auto i : each)
            {
                tmp+=i;
                tmp+=" ";
            }
            tmp=tmp.substr(0, tmp.length() - 1);
            out.push_back(tmp);
        }
        return out;
    }
    // 3rd: dp with index storage but not actual string     memory limit exceeded
    vector<string> wordBreak3(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<string> out;
        unordered_set<string> hash;
        for (auto each: wordDict)   hash.insert(each);
        vector<vector<pair<int,int>>> dp[n];
        unordered_set<int> startIndex;
        for (int i = n- 1; i>=0; i--)
        {
            unordered_set<int> tmp;
            for (auto each: startIndex)
            {
                if (hash.find(s.substr(i, each - i))!=hash.end())
                {
                    for (auto k : dp[each])
                    {
                        k.insert(k.begin(), make_pair(i, each - 1));
                        dp[i].push_back(k);
                    }
                    tmp.insert(i);
                }
            }
            for (auto each: tmp)  startIndex.insert(each);  
            if (hash.find(s.substr(i))!=hash.end())
            {
                vector<pair<int,int>> tmp{make_pair(i, n-1)};
                dp[i].push_back(tmp);
                startIndex.insert(i);
            }
        }
        for (auto each: dp[0])
        {
            string tmp = "";
            for (auto i : each)
            {
                tmp+= s.substr(i.first, i.second - i.first + 1);
                tmp+=" ";
            }
            tmp=tmp.substr(0, tmp.length() - 1);
            out.push_back(tmp);
        }
        return out;
    }
    // 4th: dfs
    vector<string> dfs(string& s, unordered_set<string>& hash, int end) //exclusive
    {
        if (end == 0)   return vector<string>();
        vector<string> out;
        int n = s.length();
        stack<int> startIndex;
        for (int i = end-1; i>=0 ;i--)
        {
            if (hash.find(s.substr(i, end-i))!=hash.end())
            {
                startIndex.push(i);
            }
        }
        if (startIndex.size() == 0)   return out;
        if (startIndex.size() == 1 && startIndex.top() == 0)
        {
            out.push_back(s.substr(0, end));
            return out;
        }
        else
        {
            while (startIndex.size() != 0)
            {
                int cur = startIndex.top();
                startIndex.pop();
                string tmp = s.substr(cur, end-cur);
                for (auto i: dfs(s, hash, cur))
                {
                    string tmpres = i +" " + tmp;
                    out.push_back(tmpres);
                }
            }
        }
        return out;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<string> out;
        unordered_set<string> hash;
        for (auto each: wordDict)   hash.insert(each);
        out = dfs(s, hash, n);
        return out;
    }
};
int main()
{
    Solution mySol;
    // vector<string> arr = {"kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"};
    // string in = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami"; 
    
    // string in = "pineapplepenapple";
    // vector<string> arr = {"apple","pen","applepen","pine","pineapple"};
    
    // string in = "aaaaaaa";
    // vector<string> arr = {"aaaa","aa","a"};
    
    string in = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> arr = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector<string> result = mySol.wordBreak1(in, arr);
    for (auto i : result)   cout<<i<<endl;
    cout<<result.size()<<endl;
    //cout<<mySol.save;
    return 0;
}
