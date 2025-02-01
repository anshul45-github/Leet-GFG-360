#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* mp = new Node();
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int n = 1 << 30;
            Node* temp = mp;
            while(n > 0) {
                if(num & n) {
                    if(temp -> left == nullptr) {
                        temp -> left = new Node();
                    }
                    temp = temp -> left;
                }
                else {
                    if(temp -> right == nullptr) {
                        temp -> right = new Node();
                    }
                    temp = temp -> right;
                }
                n = n >> 1;
            }
        }
        int maxAns = 0;
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int n = 1 << 30;
            Node* temp = mp;
            int ans = 0;
            while(temp) {
                if(x & n) {
                    if(temp -> right) {
                        ans = ans | n;
                        temp = temp -> right;
                    }
                    else
                        temp = temp -> left;
                }
                else {
                    if(temp -> left) {
                        ans = ans | n;
                        temp = temp -> left;
                    }
                    else
                        temp = temp -> right;
                }
                n = n >> 1;
            }
            maxAns = max(ans, maxAns);
        }
        return maxAns;
    }
};
