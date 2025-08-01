// https://www.geeksforgeeks.org/problems/children-sum-parent/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    int getData(Node* root) {
        return root ? root -> data : 0;
    }
    bool check(Node* root) {
        if(root == nullptr)
            return true;
        if(root -> left == nullptr && root -> right == nullptr)
            return true;
        return (root -> data == getData(root -> left) + getData(root -> right)) && check(root -> left) && check(root -> right);
    }
    int isSumProperty(Node *root)
    {
        return check(root);
    }
};
