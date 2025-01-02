#include<bits/stdc++.h>
using namespace std;

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void inorder(TreeNode* root, vector<int>& v) {
    if(root == nullptr)
        return;
    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);
}

void preorder(TreeNode* root, vector<int>& v) {
    if(root == nullptr)
        return;
    v.push_back(root -> data);
    preorder(root -> left, v);
    preorder(root -> right, v);
}

void postorder(TreeNode* root, vector<int>& v) {
    if(root == nullptr)
        return;
    postorder(root -> left, v);
    postorder(root -> right, v);
    v.push_back(root -> data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> v(3);
    inorder(root, v[0]);
    preorder(root, v[1]);
    postorder(root, v[2]);
    return v;
}
