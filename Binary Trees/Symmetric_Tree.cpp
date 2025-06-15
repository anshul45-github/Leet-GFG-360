// https://leetcode.com/problems/symmetric-tree/
// Easy

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
    bool isMirror(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr ^ q == nullptr)
            return false;
        return isMirror(p -> left, q -> right) && isMirror(p -> right, q -> left) && p -> val == q -> val;
    }
public:
    bool isSymmetricIterative(TreeNode* root) {
        if(!root) 
            return true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root -> left, root -> right});
        while(!q.empty()) {
            TreeNode* left = q.front().first;
            TreeNode* right = q.front().second;
            q.pop();
            if(!left && !right) 
                continue;
            if(!left || !right) 
                return false;
            if(left -> val != right -> val) 
                return false;
            q.push({left -> left, right -> right});
            q.push({left -> right, right -> left});
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root -> left, root -> right);
    }
};
