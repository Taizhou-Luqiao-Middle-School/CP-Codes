/*
Author:qianmo
算法：哈希表
题目链接：https://leetcode.cn/problems/maximum-number-of-pairs-in-array/
*/
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto x:nums) hash[x]++;
        vector<int> ans(2);
        for(auto [a,b]:hash)
            ans[0]+=b/2;
        ans[1]=nums.size()-ans[0]*2;
        return ans;
    }
};