// https://www.naukri.com/code360/problems/preorder-traversal_3838888?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

TreeNode* pred(TreeNode* root) {
    TreeNode* cpy = root;
    root = root -> left;
    while(root -> right && root -> right != cpy)
        root = root -> right;
    return root;
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    while(root) {
        if(root -> left == nullptr) {
            ans.push_back(root -> data);
            root = root -> right;
        }
        else {
            TreeNode* p = pred(root);
            if(p -> right == nullptr) {
                p -> right = root;
                ans.push_back(root -> data);
                root = root -> left;
            }
            else {
                p -> right = nullptr;
                root = root -> right;
            }
        }
    }
    return ans;
}