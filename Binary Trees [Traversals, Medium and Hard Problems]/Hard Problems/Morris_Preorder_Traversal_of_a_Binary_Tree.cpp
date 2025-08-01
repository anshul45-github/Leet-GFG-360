// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    TreeNode* predecessor(TreeNode* root) {
        TreeNode* cpy = root;
        root = root -> left;
        while(root -> right && root -> right != cpy)
            root = root -> right;
        return root;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        while(root) {
            if(root -> left == nullptr) {
                v.push_back(root -> val);
                root = root -> right;
            }
            else {
                TreeNode* p = predecessor(root);
                if(p -> right == nullptr) {
                    p -> right = root;
                    root = root -> left;
                }
                else {
                    p -> right = nullptr;
                    v.push_back(root -> val);
                    root = root -> right;
                }
            }
        }
        return v;
    }
};
