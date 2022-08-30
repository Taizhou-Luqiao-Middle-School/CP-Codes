/*
Author:qianmo
算法：哈希表
题目链接：https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
*/
class Solution {
public:
    int getsum(int n)
    {
        int sum=0;
        while(n!=0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> hash;
        int ans=-1;
        for(auto x:nums)
        {
            int s=getsum(x);
            if(hash.count(s)) ans=max(ans,x+hash[s]);
            hash[s]=max(hash[s],x);
        }
        return ans;
    }
};