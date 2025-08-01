// https://leetcode.com/problems/convert-bst-to-greater-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int sum;
    void postorder(TreeNode* root) {
        if(root == nullptr)
            return;
        postorder(root -> right);
        int k = root -> val;
        root -> val += sum;
        sum += k;
        postorder(root -> left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        postorder(root);
        return root;
    }
};