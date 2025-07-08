// https://www.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    vector<int> inorder;
    void traversal(Node* root) {
        if(root == nullptr)
            return;
        traversal(root -> left);
        inorder.push_back(root -> data);
        traversal(root -> right);
    }
    Node* balancedTree(int l, int r) {
        if(l > r)
            return nullptr;
        int mid = l + ((r - l) >> 1);
        Node* newNode = new Node(inorder[mid]);
        newNode -> left = balancedTree(l, mid - 1);
        newNode -> right = balancedTree(mid + 1, r);
        return newNode;
    }
  public:
    Node* balanceBST(Node* root) {
        traversal(root);
        return balancedTree(0, inorder.size() - 1);
    }
};