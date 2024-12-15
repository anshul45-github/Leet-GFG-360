#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    DLLNode* reverseDLL(DLLNode* head) {
        DLLNode* curr = head;
        DLLNode* n = curr -> next;
        while(curr) {
            curr -> next = curr -> prev;
            curr -> prev = n;
            if(!n)
                break;
            curr = n;
            n = n -> next;
        }
        return curr;
    }
};
