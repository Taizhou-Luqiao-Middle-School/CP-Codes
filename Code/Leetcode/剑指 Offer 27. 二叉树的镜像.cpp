/*
Author:qianmo
算法：递归
题目链接：https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/solution/jian-zhi-offer-27-er-cha-shu-de-jing-xia-yt85/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL) return NULL;//提前判断比较稳妥
        root->left=mirrorTree(root->left);//左子树反转
        root->right=mirrorTree(root->right);//右子树反转
        //三变量交换法
        TreeNode* u=root->left;
        root->left=root->right;
        root->right=u;
        return root;
    }
};