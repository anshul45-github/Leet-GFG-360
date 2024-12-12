#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        Node* temp = head;
        if(x == 1) {
            head = head -> next;
            temp -> next = nullptr;
            head -> prev = nullptr;
            delete temp;
            return head;
        }
        for(int i = 0; i < x - 2; i++)
            temp = temp -> next;
        Node* temp2 = temp -> next;
        temp -> next = temp -> next -> next ? temp -> next -> next : nullptr;
        if(temp -> next)
            temp -> next -> prev = temp;
        delete temp2;
        return head;
    }
};
