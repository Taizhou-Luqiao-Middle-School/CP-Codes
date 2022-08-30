/*
 * @lc app=leetcode.cn id=745 lang=cpp
 *
 * [745] 前缀和后缀搜索
 */

// @lc code=start
class WordFilter
{
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            int wordsize = word.size();
            for (int j = 1; j <= wordsize; j++)
            {
                string pre = word.substr(0, j);

                for (int k = 0; k < wordsize; k++)
                {
                    string suff = word.substr(k, wordsize);
                    mp[pre + "|" + suff] = i + 1;
                }
            }
        }
    }

    int f(string pref, string suff)
    {
        string s = pref + "|" + suff;
        return mp[s] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end
