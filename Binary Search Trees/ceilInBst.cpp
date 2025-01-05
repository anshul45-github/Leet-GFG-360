#include<bits/stdc++.h>
using namespace std;

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    int ans = -1;
    if(root -> data < input)
        ans = findCeil(root -> right, input);
    else if(root -> data == input)
        ans = root -> data;
    else
        ans = findCeil(root -> left, input);
    return ans != -1 ? ans : (root -> data > input) ? root -> data : -1;
}
