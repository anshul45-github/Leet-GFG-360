// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Hard

// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// A sub-tree of a binary tree is a tree consisting of a node in the tree and all of its descendants.

// A Binary Search Tree is a tree which satisfies the property: left subtree < root < right subtree for all nodes.

// A sum of a tree is the sum of its keys.

// A key of a node is the value of that node.

// Example 1:
// Input: root = [1,4,3,2,4,null,5]
// Output: 20
// Explanation: Maximum sum in a valid Binary Search Tree is obtained in the sub-tree with root node 3.

#include<climits>
#include<unordered_map>
#include<algorithm>
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