// https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root -> val < key)
            root -> right = deleteNode(root -> right, key);
        else if(root -> val > key)
            root -> left = deleteNode(root -> left, key);
        else {
            if(root -> left == nullptr && root -> right == nullptr)
                return nullptr;
            else if(root -> left == nullptr) {
                TreeNode* temp = root -> left;
                delete temp;
                return root -> right;
            }
            else if(root -> right == nullptr) {
                TreeNode* temp = root -> right;
                delete temp;
                return root -> left;
            }
            else {
                TreeNode* ios = root -> right;
                while(ios -> left)
                    ios = ios -> left;
                root -> val = ios -> val;
                root -> right = deleteNode(root -> right, ios -> val);
            }
        }
        return root;
    }
};