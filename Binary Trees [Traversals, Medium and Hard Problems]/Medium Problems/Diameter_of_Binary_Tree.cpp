// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameter = 0;
    int depth(TreeNode* node){
        if(node == nullptr)
            return 0;
        int left = depth(node -> left);
        int right = depth(node -> right);
        diameter = (diameter > left + right) ? diameter : left + right;
        return 1 + (left > right ? left : right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};