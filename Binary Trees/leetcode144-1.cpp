#include<bits/stdc++.h>
using namespace std;

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
    void helper(TreeNode* root, vector<int>& v) {
        if(root == nullptr) {
            return;
        }
        v.push_back(root -> val);
        helper(root -> left, v);
        helper(root -> right, v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        return v;
    }
};
