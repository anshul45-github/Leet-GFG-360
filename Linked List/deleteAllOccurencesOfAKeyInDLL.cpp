// TC : O(N), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    Node* deleteKey(Node* q) {
        if(q -> prev == nullptr) {
            Node* p = q;
            q = q -> next;
            q -> prev = nullptr;
            delete p;
            return q;
        }
        if(q -> next == nullptr) {
            Node* p = q;
            q = q -> prev;
            q -> next = nullptr;
            delete p;
            return nullptr;
        }
        Node* temp = q;
        Node* p = q -> prev;
        q = q -> next;
        p -> next = q;
        q -> prev = p;
        delete temp;
        return q;
    }
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;
        while(temp != nullptr) {
            if(temp -> data == x) {
                if(temp == *head_ref) {
                    *head_ref = deleteKey(temp);
                    temp = *head_ref;
                }
                else
                    temp = deleteKey(temp);
            }
            else
                temp = temp -> next;
        }
        return;
    }
};
