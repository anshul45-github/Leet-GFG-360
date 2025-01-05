#include<bits/stdc++.h>
using namespace std;

/*
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
    TreeNode* findInoSuc(TreeNode* root) {
        root = root -> right;
        while(root -> left)
            root = root -> left;
        return root;
    }
    TreeNode* searchNode(TreeNode* root, TreeNode* parent, int key) {
        if(root == nullptr)
            return new TreeNode(1e9);
        if(root -> val == key)
            return parent;
        if(root -> val < key)
            return searchNode(root -> right, root, key);
        return searchNode(root -> left, root, key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* targetParent = searchNode(root, nullptr, key);
        if(targetParent == nullptr) {
            targetParent = root;
            if(targetParent -> left && targetParent -> right) {
                TreeNode* ios = findInoSuc(targetParent);
                targetParent -> val = ios -> val;
                cout << targetParent -> right -> val << endl;
                targetParent -> right = deleteNode(targetParent -> right, ios -> val);
            }
            else if(targetParent -> left)
                root = root -> left;
            else if(targetParent -> right)
                root = root -> right;
            else
                root = nullptr;
            return root;
        }
        if(targetParent -> val == 1e9)
            return root;
        TreeNode* target = targetParent;
        if(target -> left && target -> left -> val == key)
            target = target -> left;
        else
            target = target -> right;
        if(target -> left && target -> right) {
            TreeNode* ios = findInoSuc(target);
            target -> val = ios -> val;
            target -> right = deleteNode(target -> right, ios -> val);
        }
        else if(target -> left) {
            if(targetParent -> left == target)
                targetParent -> left = target -> left;
            else
                targetParent -> right = target -> left;
        }
        else if(target -> right) {
            if(targetParent -> left == target)
                targetParent -> left = target -> right;
            else
                targetParent -> right = target -> right;
        }
        else {
            if(targetParent -> left == target)
                targetParent -> left = nullptr;
            else
                targetParent -> right = nullptr;
        }
        return root;
    }
};
