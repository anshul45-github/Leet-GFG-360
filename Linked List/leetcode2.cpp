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
    void addZeroes(ListNode* t, int n) {
        for(int i = 0; i < n; i++) {
            t -> next = new ListNode();
            t = t -> next;
        }
        return;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        ListNode* curr = sum;
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        int c = 0;
        while(c1 && c2) {
            int s = (c1 -> val) + (c2 -> val) + c;
            curr -> next = new ListNode(s % 10);
            c = s / 10;
            curr = curr -> next;
            c1 = c1 -> next;
            c2 = c2 -> next;
        }
        while(c1) {
            int s = (c1 -> val) + c;
            curr -> next = new ListNode(s % 10);
            c = s / 10;
            curr = curr -> next;
            c1 = c1 -> next;
        }
        while(c2) {
            int s = (c2 -> val) + c;
            curr -> next = new ListNode(s % 10);
            c = s / 10;
            curr = curr -> next;
            c2 = c2 -> next;
        }
        while(c) {
            curr -> next = new ListNode(c % 10);
            c = c / 10;
            curr = curr -> next;
        }
        curr = sum;
        sum = sum -> next;
        delete curr;
        return sum;
    }
};
