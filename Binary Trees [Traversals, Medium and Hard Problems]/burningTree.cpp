#include<bits/stdc++.h>
using namespace std;

/*
  struct Node {
      int data;
      Node *left;
      Node *right;

      Node(int val) {
          data = val;
          left = right = NULL;
      }
  };
*/

class Solution {
    map<Node*, Node*> parent;
    void findParent(Node* root) {
        if(root -> left) {
            parent[root -> left] = root;
            findParent(root -> left);
        }
        if(root -> right) {
            parent[root -> right] = root;
            findParent(root -> right);
        }
    }
    Node* find(Node* root, int key) {
        if(root == nullptr)
            return root;
        if(root -> data == key)
            return root;
        Node* left = find(root -> left, key);
        Node* right = find(root -> right, key);
        return left ? left : right;
    }
    int burn(Node* root, map<Node*, bool> burned) {
        if(burned[root] || !root)
            return 0;
        burned[root] = true;
        int time1 = burn(root -> right, burned);
        int time2 = burn(root -> left, burned);
        int time3 = burn(parent[root], burned);
        return max(time1, max(time2, time3)) + 1;
    }
  public:
    int minTime(Node* root, int key) {
        findParent(root);
        Node* target = find(root, key);
        int timer = 0;
        map<Node*, bool> burned;
        return burn(target, burned) - 1;
    }
};
