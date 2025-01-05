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
    TreeNode* insert(TreeNode* root, int Key) {
        if(root == nullptr) {
            TreeNode* r = new TreeNode(Key);
            return r;
        }
        if(Key > root -> val)
            root -> right = insert(root -> right, Key);
        else if(Key < root -> val)
            root -> left = insert(root -> left, Key);
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root, val);
    }
};
