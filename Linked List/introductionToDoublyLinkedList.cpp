#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i = 1; i < arr.size(); i++) {
            temp -> next = new Node(arr[i]);
            temp -> next -> prev = temp;
            temp = temp -> next;
        }
        return head;
    }
};
