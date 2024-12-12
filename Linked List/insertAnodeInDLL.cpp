#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        Node* temp = head;
        for(int i = 0; i < pos; i++) {
            temp = temp -> next;
        }
        Node* newNode = new Node(data);
        if(temp -> next) {
            newNode -> next = temp -> next;
            newNode -> next -> prev = newNode;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
        return head;
    }
};
