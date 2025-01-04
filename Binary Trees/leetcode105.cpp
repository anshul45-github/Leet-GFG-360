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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if(left > right)
            return nullptr;
        int pivot = left;
        while(inorder[pivot] != preorder[rootIdx])
            pivot++;
        TreeNode* newNode = new TreeNode(preorder[rootIdx]);
        rootIdx++;
        newNode -> left = build(preorder, inorder, rootIdx, left, pivot - 1);
        newNode -> right = build(preorder, inorder, rootIdx, pivot + 1, right);
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, preorder.size() - 1);
    }
};
