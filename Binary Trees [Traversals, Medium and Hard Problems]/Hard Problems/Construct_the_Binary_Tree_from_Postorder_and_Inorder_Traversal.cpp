// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& rootIdx, int left, int right) {
        if(left > right)
            return nullptr;
        int pivot = left;
        while(inorder[pivot] != postorder[rootIdx])
            pivot++;
        TreeNode* newNode = new TreeNode(postorder[rootIdx]);
        rootIdx--;
        newNode -> right = build(inorder, postorder, rootIdx, pivot + 1, right);
        newNode -> left = build(inorder, postorder, rootIdx, left, pivot - 1);
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = postorder.size() - 1;
        return build(inorder, postorder, rootIdx, 0, inorder.size() - 1);
    }
};
