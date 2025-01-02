#include<bits/stdc++.h>
using namespace std;

class Solution{
    void helper(node* root, vector<int>& v, int i) {
        if(root == nullptr)
            return;
        if((2 * i) + 1 < v.size())
            root -> left = newNode(v[(2 * i) + 1]);
        if((2 * i) + 2 < v.size())
            root -> right = newNode(v[(2 * i) + 2]);
        helper(root -> left, v, (2 * i) + 1);
        helper(root -> right, v, (2 * i) + 2);
    }
public:

    void create_tree(node* root0, vector<int> &vec){
        helper(root0, vec, 0);
    }

};
