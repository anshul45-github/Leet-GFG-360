#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* ll = new Node(arr[0]);
        Node* temp = ll;
        for(int i = 1; i < arr.size(); i++) {
            temp -> next = new Node(arr[i]);
            temp = temp -> next;
        }
        return ll;
    }
};
