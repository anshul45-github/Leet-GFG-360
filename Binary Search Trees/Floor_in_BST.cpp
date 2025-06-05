// https://www.naukri.com/code360/problems/floor-from-bst_920457?leftPanelTabValue=PROBLEM
// Moderate

// Given a Binary Search Tree and an integer x, find the floor of x in the BST.

// The floor of x is the largest element in the BST that is smaller than or equal to x.

// If no such element exists, return INT_MAX.

// The floor of x is the largest element in the BST that is smaller than or equal to x.

// Example 1:
// Input: root = [5,3,8,2,4,7,9], x = 6
// Output: 5

// Example 2:
// Input: root = [5,3,8,2,4,7,9], x = 10
// Output: 9

// Example 3:
// Input: root = [5,3,8,2,4,7,9], x = 1
// Output: INT_MAX

// Example 4:
// Input: root = [5,3,8,2,4,7,9], x = 5
// Output: 5

// Example 5:
// Input: root = [5,3,8,2,4,7,9], x = 3
// Output: 3

#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
int floorInBST(TreeNode<int> * root, int x) {
    int ans = -1;
    while(root) {
        if(root -> val == x)
            return x;
        else if(root -> val < x) {
            ans = max(ans, root -> val);
            root = root -> right;
        }
        else
            root = root -> left;
    }
    if(ans == -1)
        return INT_MAX;
    return ans;
}