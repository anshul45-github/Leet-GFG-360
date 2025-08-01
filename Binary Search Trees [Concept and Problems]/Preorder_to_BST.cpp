// https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/1

#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;


Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    temp -> left = temp -> right = NULL;
    return temp;
}

class Solution {
    vector<int> pre, in;
    unordered_map<int, int> mp;
    Node* solve(vector<int>& pre, vector<int>& in, int& k, int l, int r) {
        if(l > r)
            return nullptr;
        int pivot = mp[pre[k]];
        Node* root = newNode(pre[k]);
        k++;
        root -> left = solve(pre, in, k, l, pivot - 1);
        root -> right = solve(pre, in, k, pivot + 1, r);
        return root;
    }
  public:
    Node* Bst(int p[], int size) {
        for(int i = 0; i < size; i++)
            pre.push_back(p[i]);
        in = pre;
        sort(in.begin(), in.end());
        for(int i = 0; i < size; i++)
            mp[in[i]] = i;
        int k = 0;
        return solve(pre, in, k, 0, size - 1);
    }
};