// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  

int findCeil(Node* root, int target) {
    int ans = -1;
    while(root) {
        if(root -> data == target)
            return target;
        else if(root -> data > target) {
            ans = root -> data;
            root = root -> left;
        }
        else 
            root = root -> right;
    }
    return ans;
}