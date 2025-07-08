// https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    Node* findPre(Node* root) {
        Node* temp = root -> left;
        while(temp -> right && temp -> right != root)
            temp = temp -> right;
        return temp;
    }
  public:
    int kthSmallest(Node *root, int k) {
        int i = 0;
        Node* temp = root;
        while(temp) {
            if(temp -> left == nullptr) {
                i++;
                if(i == k)
                    return temp -> data;
                temp = temp -> right;
            }
            else {
                Node* pre = findPre(temp);
                if(pre -> right == nullptr) {
                    pre -> right = temp;
                    temp = temp -> left;
                }
                else {
                    pre -> right = nullptr;
                    i++;
                    if(i == k)
                        return temp -> data;
                    temp = temp -> right;
                }
            }
        }
        return -1;
    }
};