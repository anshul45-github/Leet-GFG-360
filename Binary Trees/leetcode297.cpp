#include<bits/stdc++.h>
using namespace std;

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string str = "";
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr) {
                str += "N ";
                continue;
            }
            str += to_string(curr -> val) + " ";
            q.push(curr -> left);
            q.push(curr -> right);
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "N ")
            return nullptr;
        int idx = 0;
        vector<int> nums;
        while(idx < data.size()) {
            int num = 0;
            bool neg = data[idx] == '-';
            if(neg)
                idx++;
            while(data[idx] != ' ') {
                if(data[idx] == 'N') {
                    idx++;
                    num = 1001;
                    break;
                }
                else
                    num = (num * 10) + (data[idx] - '0');
                idx++;
            }
            idx++;
            if(neg)
                num = -num;
            nums.push_back(num);
        }
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(nums[0]);
        q.push(root);
        idx = 1;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            curr -> left = nums[idx] == 1001 ? nullptr : new TreeNode(nums[idx]);
            idx++;
            curr -> right = nums[idx] == 1001 ? nullptr : new TreeNode(nums[idx]);
            idx++;
            if(curr -> left)
                q.push(curr -> left);
            if(curr -> right)
                q.push(curr -> right);
            q.pop();
        }
        return root;
    }
};
