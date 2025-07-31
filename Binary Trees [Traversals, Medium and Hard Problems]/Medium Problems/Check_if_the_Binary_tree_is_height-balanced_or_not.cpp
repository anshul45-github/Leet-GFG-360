// https://leetcode.com/problems/balanced-binary-tree/

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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isBalanced(root -> left) && isBalanced(root -> right) && (abs(maxDepth(root -> left) - maxDepth(root -> right)) <= 1);
    }
};
