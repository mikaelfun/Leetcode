/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;
class Solution {
public:
    //1st: recursive, time exceeded
    bool wordBreak1(string s, vector<string>& wordDict) {
        bool result = false;
        if (s.length() == 0)    return false;
        for (int i = 1; i<= s.length(); i ++)
        {
            for (auto j: wordDict)
            {
                if (j == s)     return true;
                if (j == (s.substr(0,i)))
                {
                    result = true;
                    result =  result && wordBreak(s.substr(i), wordDict);
                    if (result)     return result;
                }
            }
        }
        return result;
    }
    //2nd: dp[i]: is good ending at i
    
    bool wordBreak2(string s, vector<string>& wordDict) {
        if (s.length() == 0)    return false;
        int n = s.length();
        unordered_set<string> map;
        for (auto k: wordDict)  map.insert(k);
        bool dp[n];
        dp[0] = map.find(s.substr(0,1)) != map.end();
        for (int i = 1; i< n; i ++)
        {
            dp[i] = false;
            if (map.find(s.substr(0,i+1)) != map.end())
            {
                dp[i] = true;
            }
            else
            {
                for (int j = 1; j<=i; j++)
                {
                    if (dp[j-1] && map.find(s.substr(j, i-j+1)) != map.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        //for (auto i: dp)    cout<<i<<" ";
        return dp[n-1];
    }
    //3rd: dfs
    // no memo, time exceeded
    bool helper(string& s, unordered_set<string>& map, int l, int h) {
        if (l > h)  return false;
        if (map.find(s.substr(l, h-l + 1)) != map.end())    return true;
        for (int i = l; i<=h - 1; i++)
        {
            if (helper(s, map, l, i) && helper(s, map, i+1, h)) return true;
        }
        
        return false;
    }
    bool wordBreak3(string s, vector<string>& wordDict) {
        if (s.length() == 0)    return false;
        int n = s.length();
        unordered_set<string> map;
        for (auto k: wordDict)  map.insert(k);
        return helper(s, map, 0, n- 1);
    }
    //4th: dfs
    // with memo, time exceeded
    int dfs(string& s, unordered_set<string>& map, int l, int h, vector<vector<int>> & memo) {
        if (l > h)  return false;
        if (memo[l][h] != -1)   return memo[l][h];
        if (map.find(s.substr(l, h-l + 1)) != map.end())
        {
            memo[l][h] = 1;
            return true;
        }
        
        for (int i = l; i<h; i++)
        {
            bool left = dfs(s, map, l, i, memo);
            bool right = dfs(s, map, i+1, h, memo);
            if (left && right) 
            {
                memo[l][h] = 1;
                return true;
            }
        }
        memo[l][h] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.length() == 0)    return false;
        int n = s.length();
        unordered_set<string> map;
        for (auto k: wordDict)  map.insert(k);
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(s, map, 0, n- 1, memo) == 1;
    }
};
int main()
{
    Solution mySol;
    vector<string> arr = {"kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"};
    string in = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami"; 
    
    bool result = mySol.wordBreak2(in, arr);
    cout<<result<<endl;

    //cout<<mySol.save;
    return 0;
}
