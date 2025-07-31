// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void traverse(TreeNode* root, vector<vector<int>>& v, int x, int y) {
        if(root == nullptr)
            return;
        v.push_back({x, y, root -> val});
        traverse(root -> left, v, x - 1, y + 1);
        traverse(root -> right, v, x + 1, y + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        traverse(root, v, 0, 0);
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < 3; j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
        int curr = v[0][0];
        vector<vector<int>> ans;
        vector<int> temp = {v[0][2]};
        for(int i = 1; i < v.size(); i++) {
            if(v[i][0] == curr)
                temp.push_back(v[i][2]);
            else {
                ans.push_back(temp);
                temp.erase(temp.begin(), temp.end());
                curr = v[i][0];
                temp.push_back(v[i][2]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
