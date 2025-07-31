// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Medium

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if(temp == nullptr) {
                if(q.size())
                    q.push(nullptr);
                continue;
            }
            if(q.front())
                temp -> next = q.front();
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }
        return root;
    }
};