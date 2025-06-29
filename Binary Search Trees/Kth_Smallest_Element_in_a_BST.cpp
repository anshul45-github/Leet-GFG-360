// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

// Inorder traversal approach without using extra space.
class Solution {
    int ans;
    void inorder(TreeNode* root, int k, int& cnt) {
        if(!root)
            return;
        inorder(root -> left, k, cnt);
        cnt++;
        if(cnt == k)
            ans = root -> val;
        inorder(root -> right, k, cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        ans = -1;
        int cnt = 0;
        inorder(root, k, cnt);
        return ans;
    }
};

// Optimized for follow-up question.
class Solution {
    void computeSize(TreeNode* root, unordered_map<TreeNode*, int>& size) {
        if(!root)
            return;
        computeSize(root -> left, size);
        computeSize(root -> right, size);
        size[root] = 1 + size[root -> left] + size[root -> right];
    }
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& size, int k) {
        int leftSize = size[root -> left];
        if(leftSize + 1 == k)
            return root -> val;
        else if(leftSize >= k)
            return solve(root -> left, size, k);
        return solve(root -> right, size, k - leftSize - 1);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> size;
        size[nullptr] = 0;
        computeSize(root, size);
        return solve(root, size, k);
    }
};