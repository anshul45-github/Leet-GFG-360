// https://leetcode.com/problems/recover-binary-search-tree/

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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        while(root) {
            if(root -> left == nullptr) {
                if(pre && pre -> val > root -> val) {
                    if(!first)
                        first = pre;
                    second = root;
                }
                pre = root;
                root = root -> right;
            }
            else {
                TreeNode* p = root -> left;
                while(p -> right && p -> right != root)
                    p = p -> right;
                if(p -> right == nullptr) {
                    p -> right = root;
                    root = root -> left;
                }
                else {
                    p -> right = nullptr;
                    if(pre && pre -> val > root -> val) {
                        if(!first)
                            first = pre;
                        second = root;
                    }
                    pre = root;
                    root = root -> right;
                }
            }
        }
        swap(first -> val, second -> val);
        return;
    }
};