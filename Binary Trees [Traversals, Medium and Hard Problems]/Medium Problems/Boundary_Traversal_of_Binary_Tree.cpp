// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    vector<int> traversal;
    bool isLeafNode(Node* temp) {
        return temp -> left == nullptr && temp -> right == nullptr;
    }
    void inorder(Node* root) {
        if(root == nullptr)
            return;
        inorder(root -> left);
        if(isLeafNode(root))
            traversal.push_back(root -> data);
        inorder(root -> right);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        traversal.push_back(root -> data);
        if(isLeafNode(root))
            return traversal;
        Node* temp = root -> left;
        while(temp && !isLeafNode(temp)) {
            traversal.push_back(temp -> data);
            if(temp -> left)
                temp = temp -> left;
            else
                temp = temp -> right;
        }
        inorder(root);
        vector<int> t;
        temp = root -> right;
        while(temp && !isLeafNode(temp)) {
            t.push_back(temp -> data);
            if(temp -> right)
                temp = temp -> right;
            else
                temp = temp -> left;
        }
        for(int i = t.size() - 1; i >= 0; i--) 
            traversal.push_back(t[i]);
        return traversal;
    }
};