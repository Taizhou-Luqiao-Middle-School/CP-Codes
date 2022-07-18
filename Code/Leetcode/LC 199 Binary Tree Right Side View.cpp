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
    
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        rightView(root);
        return ans;
    }
    void rightView(TreeNode* root)
    {
        int max_level = 0;
        rightViewUtil(root, 1, &max_level);
    }
    void rightViewUtil(TreeNode* root,
				int level, int *max_level)
    {
        if (root == nullptr) return;

        if (*max_level < level)
        {
            ans.push_back(root->val);
            *max_level = level;
        }

        rightViewUtil(root->right, level + 1, max_level);
        rightViewUtil(root->left, level + 1, max_level);
    }
};