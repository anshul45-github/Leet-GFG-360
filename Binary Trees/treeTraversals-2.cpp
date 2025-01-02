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

void traversal(TreeNode* root, vector<int>& pre, vector<int>& ino, vector<int>& post) {
    if(root == nullptr)
        return;
    pre.push_back(root -> data);
    traversal(root -> left, pre, ino, post);
    ino.push_back(root -> data);
    traversal(root -> right, pre, ino, post);
    post.push_back(root -> data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> v(3);
    traversal(root, v[1], v[0], v[2]);
    return v;
}
