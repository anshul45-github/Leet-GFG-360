// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        if(root -> val < val)
            root -> right = insertIntoBST(root -> right, val);
        else if(root -> val > val)
            root -> left = insertIntoBST(root -> left, val);
        return root;
    }
};