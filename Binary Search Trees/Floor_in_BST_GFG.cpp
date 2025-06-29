// https://www.geeksforgeeks.org/problems/floor-in-bst/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  

class Solution {
  public:
    int floor(Node* root, int x) {
        int ans = -1;
        while(root) {
            if(root -> data == x)
                return x;
            else if(root -> data < x) {
                ans = root -> data;
                root = root -> right;
            }
            else
                root = root -> left;
        }
        return ans;
    }
};