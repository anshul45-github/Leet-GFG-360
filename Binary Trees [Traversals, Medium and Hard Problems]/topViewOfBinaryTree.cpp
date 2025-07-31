#include<bits/stdc++.h>
using namespace std;

class Solution {
    void traverse(Node* root, vector<vector<int>>& v, int x, int y) {
        if(root == nullptr)
            return;
        v.push_back({x, y, root -> data});
        traverse(root -> left, v, x - 1, y + 1);
        traverse(root -> right, v, x + 1, y + 1);
    }
  public:
    vector<int> topView(Node* root) {
        vector<vector<int>> v;
        traverse(root, v, 0, 0);
        stable_sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) 
                return a[0] < b[0];
            return a[1] < b[1];
        });
        int curr = v[0][0];
        vector<int> ans;
        ans.push_back(v[0][2]);
        for(int i = 1; i < v.size(); i++) {
            if(v[i][0] != curr) {
                curr = v[i][0];
                ans.push_back(v[i][2]);
            }
        }
        return ans;
    }
};
