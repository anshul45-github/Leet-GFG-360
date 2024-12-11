// TC : O(N), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

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
