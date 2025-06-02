// https://www.naukri.com/code360/problems/preorder-traversal_3838888?leftPanelTabValue=PROBLEM
// Easy

// Given a binary tree, return the preorder traversal of its nodes' values.

// Note: The preorder traversal of a binary tree is defined as follows:
// 1. Visit the root node.
// 2. Traverse the left subtree in preorder.
// 3. Traverse the right subtree in preorder.

// Example:
// Input: root = [1,null,2,3]
// Output: [1,2,3]
// Explanation: The preorder traversal of the given binary tree is [1,2,3].

// Constraints:
// The number of nodes in the tree is in the range [0, 3000].
// 0 <= Node.val <= 10^9
// The tree may be unbalanced, with the height of the tree being at most 3000.
// The tree may contain duplicate values.

// Time complexity: O(n), where n is the number of nodes in the tree.
// Space complexity: O(1) for the iterative approach, O(h) for the recursive approach, where h is the height of the tree.

// The iterative approach uses Morris Traversal to achieve O(1) space complexity.

// The recursive approach uses a stack to store the nodes, which takes O(h) space.

// The Morris Traversal algorithm is used to traverse the tree without using extra space for a stack or recursion.

// The algorithm modifies the tree structure temporarily to create a threaded binary tree, allowing for efficient traversal.

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