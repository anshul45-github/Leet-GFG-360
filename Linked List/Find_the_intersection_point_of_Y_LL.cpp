// https://leetcode.com/problems/intersection-of-two-linked-lists/
// 160. Intersection of Two Linked Lists
// Easy

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(a && b) {
            if(a == b)
                return a;
            a = a -> next;
            b = b -> next;
        }
        if(a) {
            ListNode* tempA = headA;
            while(a) {
                a = a -> next;
                tempA = tempA -> next;
            }
            a = tempA;
            b = headB;
        }
        else {
            ListNode* tempB = headB;
            while(b) {
                b = b -> next;
                tempB = tempB -> next;
            }
            b = tempB;
            a = headA;
        }
        while(a && b) {
            if(a == b)
                return a;
            a = a -> next;
            b = b -> next;
        }
        return nullptr;
    }
};