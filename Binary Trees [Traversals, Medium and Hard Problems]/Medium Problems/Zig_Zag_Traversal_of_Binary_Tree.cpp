// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
            if(levels.size() & 1)
                reverse(lvl.begin(), lvl.end());
            levels.push_back(lvl);
        }
        return levels;
    }
};