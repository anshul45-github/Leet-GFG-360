// https://leetcode.com/problems/symmetric-tree/

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

// Recursive approach
class Solution {
    bool solve(TreeNode* leftNode, TreeNode* rightNode) {
        if(leftNode == nullptr && rightNode == nullptr)
            return true;
        if(leftNode == nullptr || rightNode == nullptr)
            return false;
        return (leftNode -> val == rightNode -> val) && solve(leftNode -> left, rightNode -> right) && solve(leftNode -> right, rightNode -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root -> left, root -> right);
    }
};

// Iterative approach using queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) 
            return true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root -> left, root -> right});
        while(!q.empty()) {
            auto p = q.front();
            TreeNode* left = p.first;
            TreeNode* right = p.second;
            q.pop();
            if(!left && !right) 
                continue;
            if(!left || !right || left -> val != right -> val) 
                return false;
            q.push({left -> left, right -> right});
            q.push({left -> right, right -> left});
        }
        return true;
    }
};