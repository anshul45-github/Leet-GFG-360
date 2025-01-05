// TC : O(H), SC : O(H)
#include<bits/stdc++.h>
using namespace std;

class Solution{

public:
    int floor(Node* root, int input) {
        if (root == NULL) return -1;
    
        int ans = -1;
        if(root -> data < input)
            ans = floor(root -> right, input);
        else if(root -> data == input)
            ans = root -> data;
        else
            ans = floor(root -> left, input);
        return ans != -1 ? ans : (root -> data < input) ? root -> data : -1;
    }
};
