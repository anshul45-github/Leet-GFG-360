// Iterative solution using 2 stacks
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
        stack<int> traversal;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            if(curr -> left)
                st.push(curr -> left);
            if(curr -> right)
                st.push(curr -> right);
            traversal.push(curr -> val);
        }
        while(!traversal.empty()) {
            v.push_back(traversal.top());
            traversal.pop();
        }
        return v;
    }
};
