// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(x == 1) {
            head -> next -> prev = nullptr;
            Node* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        Node* temp = head;
        for(int i = 0; i < x - 2; i++)
            temp = temp -> next;
        Node* d = temp -> next;
        temp -> next = temp -> next -> next;
        if(temp -> next)
            temp -> next -> prev = temp;
        delete d;
        return head;
    }
};