// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
    void getAllPaths(Node* root, vector<int> path, vector<vector<int>>& allPaths) {
        if(root == nullptr) {
            return;
        }
        path.push_back(root -> data);
        if(root -> left == nullptr && root -> right == nullptr) {
            allPaths.push_back(path);
            return;
        }
        getAllPaths(root -> left, path, allPaths);
        getAllPaths(root -> right, path, allPaths);
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> allPaths;
        vector<int> path;
        getAllPaths(root, path, allPaths);
        return allPaths;
    }
};
