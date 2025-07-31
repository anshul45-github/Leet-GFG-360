// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int max_sum = INT_MIN;
    int helper(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int ans1 = max(helper(root -> left), 0);
        int ans2 = max(helper(root -> right), 0);
        int ans3 = ans1 + ans2 + root -> val;
        max_sum = max(max_sum, ans3);
        return root -> val + max(ans1, ans2);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max_sum;
    }
};