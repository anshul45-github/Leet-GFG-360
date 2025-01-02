// Iterative solution
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root)
            return v;
        stack<TreeNode*> st;
        if(root -> right)
            st.push(root -> right);
        st.push(root);
        if(root -> left)
            st.push(root -> left);
        root -> left = nullptr;
        root -> right = nullptr;
        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            if(curr -> left == nullptr && curr -> right == nullptr) {
                v.push_back(curr -> val);
                continue;
            }
            if(curr -> right)
                st.push(curr -> right);
            st.push(curr);
            if(curr -> left)
                st.push(curr -> left);
            curr -> left = nullptr;
            curr -> right = nullptr;
        }
        return v;
    }
};
