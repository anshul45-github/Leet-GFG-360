// https://www.naukri.com/code360/problems/ceil-from-bst_920464?leftPanelTabValue=PROBLEM
// Easy

#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
    ~BinaryTreeNode() {
        if (left) {
          delete left;
        }
        if (right) {
          delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *root, int x){
    int ans = INT_MAX;
    while(root) {
        if(root -> data == x)
            return x;
        else if(root -> data > x) {
            ans = min(ans, root -> data);
            root = root -> left;
        }
        else
            root = root -> right;
    }
    if(ans == INT_MAX)
        return -1;
    return ans;
}