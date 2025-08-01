// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    void postOrderSerialize(TreeNode* root, string& s) {
        if(root == nullptr) {
            s += "N,";
            return;
        }
        s += to_string(root -> val) + ",";
        postOrderSerialize(root -> left, s);
        postOrderSerialize(root -> right, s);
    }
    TreeNode* postOrderDeserialize(vector<string>& vals, int& i) {
        if(vals[i] == "N") {
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(vals[i++]));
        root -> left = postOrderDeserialize(vals, i);
        root -> right = postOrderDeserialize(vals, i);
        return root;
    }
public:
    string serialize(TreeNode* root) {
        string s = "";
        postOrderSerialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        int i = 0;
        while(i < data.size()) {
            string curr = "";
            while(data[i] != ',') {
                curr += data[i];
                i++;
            }
            vals.push_back(curr);
            i++;
        }
        i = 0;
        return postOrderDeserialize(vals, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));