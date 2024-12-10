#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return root;
        if(root -> val == val)
            return root;
        if(root -> val < val)
            return searchBST(root -> right, val);
        return searchBST(root -> left, val);
    }
};
