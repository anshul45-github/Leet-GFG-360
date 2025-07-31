#include<bits/stdc++.h>
using namespace std;

/**
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int ans1 = diameterOfBinaryTree(root -> left);
        int ans2 = diameterOfBinaryTree(root -> right);
        int ans3 = maxDepth(root -> left) + maxDepth(root -> right);
        cout << root -> val << " : " << max(ans1, max(ans2, ans3)) << endl;
        return max(ans1, max(ans2, ans3));
    }
};
