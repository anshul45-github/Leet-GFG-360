// https://www.geeksforgeeks.org/problems/brothers-from-different-root/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    void inorder(Node* root, vector<int>& v) {
        if(root == nullptr)
            return;
        inorder(root -> left, v);
        v.push_back(root -> data);
        inorder(root -> right, v);
    }
  public:
    int countPairs(Node* root1, Node* root2, int x) {
        vector<int> inorder1;
        vector<int> inorder2;
        inorder(root1, inorder1);
        inorder(root2, inorder2);
        int i = 0, j = inorder2.size() - 1, ans = 0;
        while(i < inorder1.size() && j >= 0) {
            if(inorder1[i] + inorder2[j] == x) {
                ans++;
                i++;
                j--;
            }
            else if(inorder1[i] + inorder2[j] > x)
                j--;
            else
                i++;
        }
        return ans;
    }
};