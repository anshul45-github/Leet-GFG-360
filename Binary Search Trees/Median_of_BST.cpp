// https://www.geeksforgeeks.org/problems/median-of-bst/1

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

void inorder(struct Node* root, int sz, int& first, int& second, int& i) {
    if(root == nullptr)
        return;
    inorder(root -> left, sz, first, second, i);
    if(i == sz / 2 - 1)
        first = root -> data;
    else if(i == sz / 2)
        second = root -> data;
    i++;
    inorder(root -> right, sz, first, second, i);
}

int count(struct Node* root) {
    if(root == nullptr)
        return 0;
    return 1 + count(root -> left) + count(root -> right);
}

float findMedian(struct Node *root) {
    int sz = count(root);
    int first;
    int second;
    int i = 0;
    inorder(root, sz, first, second, i);
    if(sz & 1)
        return second;
    return (first + second) / (double)2;
}