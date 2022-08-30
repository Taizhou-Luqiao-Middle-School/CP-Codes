/*
Author:qianmo
算法：滑动窗口，双指针
题目链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,ans=0;
        set<char> let;
        while(r<s.length())
        {
            while(r<s.length()&& !let.count(s[r])) let.insert(s[r++]);
            ans=max(ans,r-l);
            let.erase(s[l++]);
        }
        return ans;
    }
};