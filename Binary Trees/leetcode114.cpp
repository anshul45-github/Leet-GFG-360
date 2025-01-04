#include<bits/stdc++.h>
using namespace std;

/*
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
    TreeNode* predecessor(TreeNode* root) {
        TreeNode* cpy = root;
        root = root -> left;
        while(root -> right)
            root = root -> right;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        while(root) {
            if(root -> left == nullptr) {
                // v.push_back(root -> val);
                root = root -> right;
            }
            else {
                TreeNode* p = predecessor(root);
                p -> right = root -> right;
                TreeNode* cpy = root;
                root = root -> left;
                cpy -> right = cpy -> left;
                cpy -> left = nullptr;
            }
        }
        return;
    }
};
