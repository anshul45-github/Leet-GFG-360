#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* shift(ListNode* t, int n) {
        for(int i = 0; i < n; i++)
            t = t -> next;
        return t;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size = 0;
        ListNode* curr = headA;
        while(curr) {
            size++;
            curr = curr -> next;
        }
        curr = headB;
        while(curr) {
            size--;
            curr = curr -> next;
        }
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        if(size > 0)
            t1 = shift(t1, size);
        else if(size < 0)
            t2 = shift(t2, -size);
        while(t1 != nullptr) {
            if(t1 == t2)
                return t1;
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return nullptr;
    }
};
