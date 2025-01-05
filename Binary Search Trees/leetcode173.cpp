// implemented next() and hasNext() to run in average O(1) time and use O(1) memory.
#include<bits/stdc++.h>
using namespace std;

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/

class BSTIterator {
    TreeNode* root;
    TreeNode* findInoPre(TreeNode* root) {
        TreeNode* curr = root -> left;
        while(curr -> right && curr -> right != root)
            curr = curr -> right;
        return curr;
    }
public:
    BSTIterator(TreeNode* root) {
        this -> root = root;
    }
    
    int next() {
        int ans = -1;
        while(ans == -1) {
            if(root -> left == nullptr) {
                ans = root -> val;
                root = root -> right;
            }
            else {
                TreeNode* predecessor = findInoPre(root);
                if(predecessor -> right == nullptr) {
                    predecessor -> right = root;
                    root = root -> left;
                }
                else {
                    ans = root -> val;
                    predecessor -> right = nullptr;
                    root = root -> right;
                }
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return root != nullptr;
    }
};

/*
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
*/
