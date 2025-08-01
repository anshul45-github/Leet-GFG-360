// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if(left > right)
            return nullptr;
        int pivot = left;
        while(preorder[rootIdx] != inorder[pivot])
            pivot++;
        TreeNode* newNode = new TreeNode(preorder[rootIdx]);
        rootIdx++;
        newNode -> left = build(preorder, inorder, rootIdx, left, pivot - 1);
        newNode -> right = build(preorder, inorder, rootIdx, pivot + 1, right);
        return newNode;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int idx = 0;
        return build(preorder, inorder, idx, 0, inorder.size() - 1);
    }
};