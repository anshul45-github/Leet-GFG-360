// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(!st.empty() || temp != nullptr) {
            if(temp == nullptr) {
                temp = st.top();
                st.pop();
                ans.push_back(temp -> val);
                temp = temp -> right;
            }
            else {
                st.push(temp);
                temp = temp -> left;
            }
        }
        return ans;
    }
};