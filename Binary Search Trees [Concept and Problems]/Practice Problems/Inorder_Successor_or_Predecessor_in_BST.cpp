// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* successor = root;
        Node* suc = nullptr;
        while(successor) {
            if(successor -> data > key) {
                suc = successor;
                successor = successor -> left;
            }
            else
                successor = successor -> right;
        }
        Node* predecessor = root;
        Node* pre = nullptr;
        while(predecessor) {
            if(predecessor -> data < key) {
                pre = predecessor;
                predecessor = predecessor -> right;
            }
            else
                predecessor = predecessor -> left;
        }
        return {pre, suc};
    }
};