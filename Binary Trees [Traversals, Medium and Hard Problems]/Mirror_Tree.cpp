// https://www.geeksforgeeks.org/problems/mirror-tree/1
// Easy

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void mirror(Node* node) {
        if(node == nullptr)
            return;
        Node* temp = node -> left;
        node -> left = node -> right;
        node -> right = temp;
        mirror(node -> left);
        mirror(node -> right);
    }
};