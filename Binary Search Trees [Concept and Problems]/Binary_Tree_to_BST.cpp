// https://www.geeksforgeeks.org/problems/binary-tree-to-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    vector<int> inorderTraversal;
    int k;
    void inorder(Node* root) {
        if(root == nullptr)
            return;
        inorder(root -> left);
        inorderTraversal.push_back(root -> data);
        inorder(root -> right);
    }
    void inorderUpdate(Node* root) {
        if(root == nullptr)
            return;
        inorderUpdate(root -> left);
        root -> data = inorderTraversal[k++];
        inorderUpdate(root -> right);
    }
  public:
    Node *binaryTreeToBST(Node *root) {
        inorder(root);
        sort(inorderTraversal.begin(), inorderTraversal.end());
        k = 0;
        inorderUpdate(root);
        return root;
    }
};