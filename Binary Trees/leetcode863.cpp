#include<bits/stdc++.h>
using namespace std;

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

class Solution {
    void setParents(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if(root -> left) {
            mp[root -> left] = root;
            setParents(root -> left, mp);
        }
        if(root -> right) {
            mp[root -> right] = root;
            setParents(root -> right, mp);
        }
    }
    void dfs(TreeNode* root, int k, vector<int>& ans, map<TreeNode*, bool>& vis, map<TreeNode*, TreeNode*> mp) {
        if(vis[root])
            return;
        vis[root] = true;
        if(k == 0)
            ans.push_back(root -> val);
        if(root -> left)
            dfs(root -> left, k - 1, ans, vis, mp);
        if(root -> right)
            dfs(root -> right, k - 1, ans, vis, mp);
        if(mp[root])
            dfs(mp[root], k - 1, ans, vis, mp);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        setParents(root, mp);
        TreeNode* curr = target;
        // apply dfs
        vector<int> ans;
        map<TreeNode*, bool> vis;
        dfs(target, k, ans, vis, mp);
        return ans;
    }
};
