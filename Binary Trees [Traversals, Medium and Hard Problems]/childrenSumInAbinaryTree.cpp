#include<bits/stdc++.h>
using namespace std;

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
