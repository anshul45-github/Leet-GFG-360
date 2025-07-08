// https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution {
    Node* prev;
    void inorder(Node* root) {
        if(root == nullptr)
            return;
        inorder(root -> left);
        if(prev)
            prev -> next = root;
        prev = root;
        inorder(root -> right);
    }
  public:
    void populateNext(Node *root) {
        prev = nullptr;
        inorder(root);
    }
};