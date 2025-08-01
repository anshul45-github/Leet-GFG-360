// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long maxLen = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        while(!q.empty()) {
            long long start = q.front().second;
            long long end = q.back().second;
            long long size = q.size();
            maxLen = max(maxLen, end - start + 1);
            for(int i = 0; i < size; i++) {
                long long idx = q.front().second - start;
                if(q.front().first -> left)
                    q.push({q.front().first -> left, (long long)2 * idx});
                if(q.front().first -> right)
                    q.push({q.front().first -> right, (long long)2 * idx + 1});
                q.pop();
            }
        }
        return maxLen;
    }
};