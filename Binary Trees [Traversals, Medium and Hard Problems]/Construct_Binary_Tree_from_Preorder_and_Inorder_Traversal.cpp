// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Medium

// Problem Statement:
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Example 1:
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Explanation: The binary tree is shown below:
//    3
//   / \
//  9  20
//    /  \
//   15   7

// Example 2:
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

// Constraints:
// 1 <= preorder.length <= 3000
// preorder.length == inorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.

// Approach:
// 1. Use a map to store the indices of elements in the inorder array for quick access.
// 2. Use a recursive function to build the tree using the preorder and inorder arrays.
// 3. The function takes the current index in preorder and the range of indices in inorder to construct the left and right subtrees.

#include <vector>
#include <unordered_map>
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
    int idx;
    unordered_map<int, int> mp;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(l > r)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[idx]);
        int i = mp[preorder[idx]];
        idx++;
        root -> left = solve(preorder, inorder, l, i - 1);
        root -> right = solve(preorder, inorder, i + 1, r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};