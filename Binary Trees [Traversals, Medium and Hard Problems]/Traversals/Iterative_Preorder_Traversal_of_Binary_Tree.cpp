// https://leetcode.com/problems/binary-tree-preorder-traversal/

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

// Iterative approach for Preorder Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            ans.push_back(node -> val);
            if(node -> right)
                st.push(node -> right);
            if(node -> left)
                st.push(node -> left);
        }
        return ans;
    }
};

// Morris Traversal for Preorder Traversal
class Solution {
    TreeNode* calculatePre(TreeNode* root) {
        TreeNode* temp = root;
        temp = temp -> left;
        while(temp -> right && temp -> right != root)
            temp = temp -> right;
        return temp;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* temp = root;
        while(temp) {
            if(temp -> left == nullptr) {
                ans.push_back(temp -> val);
                temp = temp -> right;
            }
            else {
                TreeNode* pre = calculatePre(temp);
                if(pre -> right) {
                    pre -> right = nullptr;
                    temp = temp -> right;
                }
                else {
                    pre -> right = temp;
                    ans.push_back(temp -> val);
                    temp = temp -> left;
                }
            }
        }
        return ans;
    }
};