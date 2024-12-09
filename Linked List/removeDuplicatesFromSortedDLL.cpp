// TC : O(N), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    Node* deleteKey(Node* k) {
        Node* p = k -> prev;
        p -> next = k -> next;
        if(k -> next)
            k -> next -> prev = p;
        delete k;
        return p;
    }
public:

    Node * removeDuplicates(struct Node *head) {
        Node* temp = head;
        while(temp) {
            if(temp -> next && temp -> next -> data == temp -> data) {
                temp = deleteKey(temp -> next);
            }
            else
                temp = temp -> next;
        }
        return head;
    }
};
