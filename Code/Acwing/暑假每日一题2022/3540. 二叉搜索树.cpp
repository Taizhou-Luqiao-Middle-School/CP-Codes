/*
Author:qianmo
算法：二叉树的遍历，二叉搜索树
题目链接：https://www.acwing.com/problem/content/description/3543/
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left,*right;
};

Node* newnode(int v)
{
    Node *temp=new Node;
    temp->val = v;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root,int num)
{
    if(root == NULL) return newnode(num);
    if(num > root->val) root->right = insert(root->right,num);
    else if(num < root->val) root->left = insert(root->left,num);
    return root;
}

void pre(Node* root)
{
    if(root == NULL) return;
    cout << root->val << " ";
    pre(root->left);
    pre(root->right);
}

void in(Node* root)
{
    if(root == NULL) return;
    in(root->left);
    cout << root->val << " ";
    in(root->right);
}

void post(Node* root)
{
    if(root == NULL) return;
    post(root->left);
    post(root->right);
    cout << root->val << " ";
}

Node *root=NULL;
int nums;

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        cin >> nums;
        root = insert(root,nums);
    }
    pre(root);
    cout << endl;
    in(root);
    cout << endl;
    post(root);
    return 0;
}