// https://leetcode.com/problems/validate-binary-search-tree/

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
    long prev = LONG_MIN;
    bool ans = true;
    void inorder(TreeNode* root) {
        if(!root)
            return;
        inorder(root -> left);
        if(prev >= 1L * root -> val)
            ans = false;
        prev = root -> val;
        inorder(root -> right);
    }
public:
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};