/*
Author:qianmo
算法：归并模拟
题目链接：https://leetcode.cn/problems/median-of-two-sorted-arrays/
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(),len2=nums2.size(),k=0,i=0,j=0;
        vector<int> nums(len1+len2,0);
        while(i<len1 && j<len2)
            nums[k++]=nums1[i]<nums2[j]?nums1[i++]:nums2[j++];
        while(i<len1) nums[k++]=nums1[i++];
        while(j<len2) nums[k++]=nums2[j++];
        int len=len1+len2;
        return len%2==0?(nums[len/2]+nums[len/2-1])/2.00:nums[len/2];
    }
};