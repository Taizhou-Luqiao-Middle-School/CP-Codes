/*
Author:qianmo
算法：二叉树的中序遍历，DFS
题目链接：https://leetcode.cn/problems/recover-binary-search-tree/solution/-by-qianmo_su-cs82/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *u,vector<int>&res)//中序遍历
    {
        if(u==NULL) return;//递归边界
        dfs(u->left,res);//遍历左子树
        res.push_back(u->val);//放入根节点
        dfs(u->right,res);//遍历右子树
    }
    void recover(TreeNode *u,vector<int>&res)//恢复二叉树
    {
        if(u==NULL) return;//递归边界
        recover(u->left,res);//恢复左子树
        if(u->val==res[0]) res.erase(res.begin());//正确的话，擦除这个元素
        else//否则，把节点值变为第一个元素，并擦掉这个元素
        {
            u->val=res[0];
            res.erase(res.begin());
        }
        recover(u->right,res);//恢复右子树
    }
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        dfs(root,inorder);
        sort(inorder.begin(),inorder.end());//冒泡排序
        recover(root,inorder);
    }
};