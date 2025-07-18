// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        TreeNode *l = root, *r = root;
        int leftHeight = 0;
        int rightHeight = 0;
        while(l) {
            l = l -> left;
            leftHeight++;
        }
        while(r) {
            r = r -> right;
            rightHeight++;
        }
        if(leftHeight == rightHeight)
            return ((1 << leftHeight) - 1);
        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};