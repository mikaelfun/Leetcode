class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int arrlen = strs.size();
        if (arrlen == 0)    return "";
        if (arrlen == 1)    return strs[0];

        for (int i = 0; i<strs[0].length(); i++)
        {
            for (int j = 1; j<arrlen;j++)
            {
                if  (i>=strs[j].length())   return strs[0].substr(0,i);
                if (strs[j][i] != strs[0][i])
                {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};