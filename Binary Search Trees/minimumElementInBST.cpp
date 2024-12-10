#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(Node* root) {
        while(root -> left)
            root = root -> left;
        return root -> data;
    }
};
