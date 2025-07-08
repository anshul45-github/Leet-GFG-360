// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

#include <bits/stdc++.h>
using namespace std;

// Tree Node
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
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(n1 -> data > n2 -> data)
            return LCA(root, n2, n1);
        Node* temp = root;
        while(temp) {
            if(temp == n1 || temp == n2)
                return temp;
            if(temp -> data > n1 -> data && temp -> data < n2 -> data)
                return temp;
            if(temp -> data > n2 -> data)
                temp = temp -> left;
            else
                temp = temp -> right;
        }
        return nullptr;
    }
};