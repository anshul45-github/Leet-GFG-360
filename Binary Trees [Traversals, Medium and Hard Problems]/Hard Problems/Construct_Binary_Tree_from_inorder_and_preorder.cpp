// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <vector>
#include <unordered_map>
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
    int idx;
    unordered_map<int, int> mp;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(l > r)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[idx]);
        int i = mp[preorder[idx]];
        idx++;
        root -> left = solve(preorder, inorder, l, i - 1);
        root -> right = solve(preorder, inorder, i + 1, r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};