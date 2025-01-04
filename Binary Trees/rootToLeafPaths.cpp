#include<bits/stdc++.h>
using namespace std;

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
