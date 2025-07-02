// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
  public:
    Node *addNode(Node *head, int pos, int data) {
        Node* temp = head;
        for(int i = 0; i < pos; i++)
            temp = temp -> next;
        Node* newNode = new Node(data);
        newNode -> prev = temp;
        newNode -> next = temp -> next;
        if(newNode -> next)
            newNode -> next -> prev = newNode;
        newNode -> prev -> next = newNode;
        return head;
    }
};