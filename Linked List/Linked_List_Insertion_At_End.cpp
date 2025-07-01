// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        if(head == nullptr) {
            return new Node(x);
        }
        Node* temp = head;
        while(temp -> next)
            temp = temp -> next;
        temp -> next = new Node(x);
        return head;
    }
};
