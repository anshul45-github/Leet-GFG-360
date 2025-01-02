// TC : O(1), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

/*
struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}
*/

class Solution{
public:
    void create_tree(node* root0, vector<int> &vec){
        root0 -> left = newNode(vec[1]);
        root0 -> right = newNode(vec[2]);
        root0 -> left -> left = newNode(vec[3]);
        root0 -> left -> right = newNode(vec[4]);
        root0 -> right -> left = newNode(vec[5]);
        root0 -> right -> right = newNode(vec[6]);
    }
};
