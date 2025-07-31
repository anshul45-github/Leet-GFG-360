// https://www.geeksforgeeks.org/problems/postorder-traversal-iterative/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        stack<Node*> st1;
        stack<Node*> st2;
        st1.push(root);
        while(!st1.empty()) {
            auto node = st1.top();
            st1.pop();
            st2.push(node);
            if(node -> left)
                st1.push(node -> left);
            if(node -> right)
                st1.push(node -> right);
        }
        vector<int> ans;
        while(!st2.empty()) {
            ans.push_back(st2.top() -> data);
            st2.pop();
        }
        return ans;
    }
};