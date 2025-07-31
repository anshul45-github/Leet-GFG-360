// https://leetcode.com/problems/binary-tree-level-order-traversal/

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

// Approach 1: Using Queue For Breadth-First Search (BFS)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> lvl;
            for(int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                lvl.push_back(node -> val);
                if(node -> left)
                    q.push(node -> left);
                if(node -> right)
                    q.push(node -> right);
            }
            levels.push_back(lvl);
        }
        return levels;
    }
};

// Approach 2: Using Recursive Way Depth-First Search Beats 42.5%
class Solution {
    void helper(TreeNode* root, int level, vector<vector<int>>& ans) {
        if(root == nullptr)
            return;
        if(level == ans.size())
            ans.resize(level + 1);
        ans[level].push_back(root -> val);
        helper(root -> left, level + 1, ans);
        helper(root -> right, level + 1, ans);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, 0, ans);
        return ans;
    }
};