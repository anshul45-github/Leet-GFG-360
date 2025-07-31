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
    int solve(TreeNode* root, int maxi) {
        if(root == nullptr)
            return 0;
        maxi = max(maxi, root -> val);
        int ans = solve(root -> left, maxi) + solve(root -> right, maxi);
        if((root -> val) >= maxi) 
            return ans + 1;
        return ans;
    }
public:
    int goodNodes(TreeNode* root) {
        int currMax = root -> val;
        return solve(root, currMax);
    }
};