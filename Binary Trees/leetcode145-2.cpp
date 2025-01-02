// Iterative solution using 1 stack
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root)
            return v;
        stack<TreeNode*> st;
        st.push(root);
        if(root -> right)
            st.push(root -> right);
        if(root -> left)
            st.push(root -> left);
        root -> left = nullptr;
        root -> right = nullptr;
        while(!st.empty()) {
            TreeNode* curr = st.top();
            if(curr -> left == nullptr && curr -> right == nullptr) {
                v.push_back(curr -> val);
                st.pop();
                continue;
            }
            if(curr -> right)
                st.push(curr -> right);
            if(curr -> left)
                st.push(curr -> left);
            curr -> left = nullptr;
            curr -> right = nullptr;
        }
        return v;
    }
};
