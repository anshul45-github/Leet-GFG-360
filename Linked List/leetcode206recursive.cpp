#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void moveHeadToTail(ListNode* head, ListNode* tail) {
        if(head == tail)
            return;
        ListNode* temp = head -> next;
        head -> next = tail -> next;
        tail -> next = head;
        moveHeadToTail(temp, tail);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* tail = head;
        while(tail -> next)
            tail = tail -> next;
    
        moveHeadToTail(head, tail);

        return tail;
    }
};
