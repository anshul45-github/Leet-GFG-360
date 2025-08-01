// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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

class Node {
public:
    int sum;
    bool isBST;
    int maxi;
    int mini;
    Node() {
        maxi = INT_MIN;
        mini = INT_MAX;
        isBST = false;
        sum = 0;
    }
};

class Solution {
    unordered_map<TreeNode*, Node*> mp;
    void postorder(TreeNode* root, int& maxSum) { 
        if(root == nullptr)
            return;
        postorder(root -> left, maxSum);
        postorder(root -> right, maxSum);
        mp[root] = new Node();
        mp[root] -> isBST = (root -> val > mp[root -> left] -> maxi) && (root -> val < mp[root -> right] -> mini) && mp[root -> left] -> isBST && mp[root -> right] -> isBST;
        mp[root] -> sum = mp[root -> left] -> sum + mp[root -> right] -> sum + root -> val;
        mp[root] -> maxi = max(max(root -> val, mp[root -> left] -> maxi), mp[root -> right] -> maxi);
        mp[root] -> mini = min(min(root -> val, mp[root -> left] -> mini), mp[root -> right] -> mini);
        if(mp[root] -> isBST)
            maxSum = max(maxSum, mp[root] -> sum);
    }
public:
    int maxSumBST(TreeNode* root) {
        Node* null = new Node();
        mp[nullptr] = null;
        mp[nullptr] -> isBST = true;
        int maxSum = 0;
        postorder(root, maxSum);
        return maxSum;
    }
};

// Alternative solution using vector to store sum, max, and min values
class Solution {
    int ans;
    vector<int> solve(TreeNode* root) {
        if(root == nullptr)
            return {0, INT_MIN, INT_MAX}; 
        vector<int> left = solve(root -> left);
        vector<int> right = solve(root -> right);
        if(root -> val > left[1] && root -> val < right[2]) {
            ans = max(ans, left[0] + right[0] + root -> val);
            return {left[0] + right[0] + root -> val, max(root -> val, right[1]), min(root -> val, left[2])};
        }
        return {max(left[0], right[0]), INT_MAX, INT_MIN};
    }
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root)[0];
        return ans;
    }
};