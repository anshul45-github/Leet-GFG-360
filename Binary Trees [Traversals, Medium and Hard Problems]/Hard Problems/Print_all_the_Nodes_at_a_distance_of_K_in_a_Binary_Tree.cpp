// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> ans;
    void dfs(TreeNode* root) {
        if(root -> left) {
            parent[root -> left] = root;
            dfs(root -> left);
        }
        if(root -> right) {
            parent[root -> right] = root;
            dfs(root -> right);
        }
    }
    void findDistantNodes(TreeNode* target, TreeNode* prev, int k) {
        if(k == 0) {
            ans.push_back(target -> val);
            return;
        }
        if(parent[target] && parent[target] != prev)
            findDistantNodes(parent[target], target, k - 1);
        if(target -> left && target -> left != prev)
            findDistantNodes(target -> left, target, k - 1);
        if(target -> right && target -> right != prev)
            findDistantNodes(target -> right, target, k - 1);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        findDistantNodes(target, nullptr, k);
        return ans;
    }
};