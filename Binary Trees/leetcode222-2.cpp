// an algorithm that runs in less than O(n) time complexity
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
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode* l = root;
        TreeNode* r = root;
        while(l) {
            leftHeight++;
            l = l -> left;
        }
        while(r) {
            rightHeight++;
            r = r -> right;
        }
        if(leftHeight == rightHeight)
            return pow(2, leftHeight) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
