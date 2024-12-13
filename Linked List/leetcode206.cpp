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
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* tail = head;
        while(tail -> next)
            tail = tail -> next;
        while(head != tail) {
            ListNode* temp = head -> next;
            head -> next = tail -> next;
            tail -> next = head;
            head = temp;
        }
        return tail;
    }
};
