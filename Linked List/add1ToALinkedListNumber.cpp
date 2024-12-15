// TC : O(N), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    Node* reverseList(Node* head) {
        Node* curr = head;
        Node* n = curr -> next;
        Node* prev = nullptr;
        while(curr) {
            curr -> next = prev;
            prev = curr;
            if(!n)
                return curr;
            curr = n;
            if(n)
                n = n -> next;
        }
    }
  public:
    Node* addOne(Node* head) {
        Node* reverseHead = reverseList(head);
        Node* curr = reverseHead;
        while(curr -> next && curr -> data == 9) {
            curr -> data = 0;
            curr = curr -> next;
        }
        if(curr -> data == 9) {
            curr -> data = 0;
            curr -> next = new Node(1);
        }
        else {
            curr -> data = (curr -> data) + 1;
        }
        head = reverseList(reverseHead);
        return head;
    }
};
