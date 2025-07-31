// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
    void solve(Node* root, int level, vector<int>& ans) {
        if(root == nullptr)
            return;
        if(level > ans.size())
            ans.push_back(root -> data);
        solve(root -> left, level + 1, ans);
        solve(root -> right, level + 1, ans);
    }
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        solve(root, 1, ans);
        return ans;
    }
};