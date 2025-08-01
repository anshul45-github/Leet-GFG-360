// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
// Easy

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

class Solution {
    void solve(Node* root, int& k, int& ans) {
        if(root == nullptr || ans != -1)
            return;
        solve(root -> right, k, ans);
        k--;
        if(k == 0)
            ans = root -> data;
        solve(root -> left, k, ans);
    }
  public:
    int kthLargest(Node *root, int k) {
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
};