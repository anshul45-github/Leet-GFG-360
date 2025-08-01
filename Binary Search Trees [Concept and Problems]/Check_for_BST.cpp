// https://www.geeksforgeeks.org/problems/check-for-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
    bool check(Node* root, int mini, int maxi) {
        if(root == nullptr)
            return true;
        if(root -> data < mini || root -> data > maxi)
            return false;
        return check(root -> left, mini, root -> data) && check(root -> right, root -> data, maxi);
    }
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        return check(root, INT_MIN, INT_MAX);
    }
};