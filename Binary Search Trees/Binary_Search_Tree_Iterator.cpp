// https://leetcode.com/problems/binary-search-tree-iterator/

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

// Approach 1 - Morris Traversal
class BSTIterator {
    TreeNode* root;
public:
    BSTIterator(TreeNode* root) {
        this -> root = root;
    }

    TreeNode* findPre(TreeNode* root) {
        TreeNode* temp = root -> left;
        while(temp -> right && temp -> right != root)
            temp = temp -> right;
        return temp;
    }
    
    int next() {
        while(root) {
            if(root -> left == nullptr) {
                int x = root -> val;
                root = root -> right;
                return x;
            }
            TreeNode* pre = findPre(root);
            if(pre -> right == nullptr) {
                pre -> right = root;
                root = root -> left;
            }
            else {
                pre -> right = nullptr;
                int x = root -> val;
                root = root -> right;
                return x;
            }
        }
        return -1;
    }
    
    bool hasNext() {
        return root;
    }
};

// Approach 2 - Using Stack
class BSTIterator {
public:
    stack<TreeNode*>st;
    void pushleft(TreeNode*root) {
        while(root) {
            st.push(root);
            root = root -> left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushleft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushleft(node -> right);
        return node -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */