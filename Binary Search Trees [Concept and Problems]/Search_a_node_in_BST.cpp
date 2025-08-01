// https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to search a node in BST.
bool search(Node* root, int x) {
    if(!root)
        return false;
    if(root -> data == x)
        return true;
    if(root -> data > x)
        return search(root -> left, x);
    return search(root -> right, x);
}