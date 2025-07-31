//https://leetcode.com/problems/binary-tree-right-side-view/

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
    void preorder(TreeNode* root, map<int, int>& mp, int y) {
        if(root == nullptr)
            return;
        mp[y] = root -> val;
        preorder(root -> left, mp, y + 1);
        preorder(root -> right, mp, y + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mp;
        preorder(root, mp, 0);
        vector<int> ans;
        for(const auto& pair : mp)
            ans.push_back(pair.second);
        return ans;
    }
};
