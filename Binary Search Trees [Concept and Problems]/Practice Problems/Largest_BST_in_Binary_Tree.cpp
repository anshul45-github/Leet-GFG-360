// https://www.geeksforgeeks.org/problems/largest-bst/1

#include<bits/stdc++.h>
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

class Solution{
    vector<int> helper(Node* root) {
        if(root == nullptr) {
            return {0, INT_MAX, INT_MIN};
        }
        vector<int> left = helper(root -> left);
        vector<int> right = helper(root -> right);
        if(root -> data > left[2] && root -> data < right[1])
            return {1 + left[0] + right[0], min(root -> data, left[1]), max(root -> data, right[2])};
        else
            return {max(left[0], right[0]), INT_MIN, INT_MAX};
    }
    public:
    int largestBst(Node *root)
    {
        return helper(root)[0];
    }
};