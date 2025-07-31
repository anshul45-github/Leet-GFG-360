// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> ans;
    void helper(TreeNode* root) {
        if(root == nullptr)
            return;
        ans.push_back(root -> val);
        helper(root -> left);
        helper(root -> right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};