// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

// Optimized Inorder Traversal: Morris Traversal
class Solution {
    TreeNode* pre(TreeNode* root) {
        TreeNode* cpy = root -> left;
        while(cpy -> right && cpy -> right != root)
            cpy = cpy -> right;
        return cpy;
    }
    void inorder(TreeNode* root, vector<int>& v) {
        while(root) {
            if(root -> left == nullptr) {
                v.push_back(root -> val);
                root = root -> right;
            }
            else {
                TreeNode* p = pre(root);
                if(p -> right == nullptr) {
                    p -> right = root;
                    root = root -> left;
                }
                else {
                    v.push_back(root -> val);
                    p -> right = nullptr;
                    root = root -> right;
                }
            }
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        int i = 0, j = v.size() - 1;
        while(i < j) {
            if(v[i] + v[j] == k)
                return true;
            else if(v[i] + v[j] < k)
                i++;
            else
                j--;
        }
        return false;
    }
};

// Recursive Inorder Traversal Approach
class Solution {
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == nullptr)
            return;
        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        int i = 0, j = v.size() - 1;
        while(i < j) {
            if(v[i] + v[j] == k)
                return true;
            else if(v[i] + v[j] < k)
                i++;
            else
                j--;
        }
        return false;
    }
};