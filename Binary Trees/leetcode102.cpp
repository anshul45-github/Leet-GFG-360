#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == nullptr)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> temp;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            if(!curr) {
                v.push_back(temp);
                temp.erase(temp.begin(), temp.end());
                q.pop();
                if(q.size() > 0)
                    q.push(nullptr);
                continue;
            }
            if(curr -> left)
                q.push(curr -> left);
            if(curr -> right)
                q.push(curr -> right);
            temp.push_back(curr -> val);
            q.pop();
        }
        if(temp.size())
            v.push_back(temp);
        return v;
    }
};
