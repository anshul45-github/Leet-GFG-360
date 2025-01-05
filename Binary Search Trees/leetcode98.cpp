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
    bool helper(TreeNode* root, long long mini, long long maxi) {
        if(!root)
            return true;
        bool ans = root -> val >= mini && root -> val <= maxi;
        return ans && helper(root -> left, mini, min(maxi, 1LL * root -> val) - 1) && helper(root -> right, min(maxi, 1LL * root -> val) + 1, maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};
