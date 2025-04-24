// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// 19. Remove Nth Node From End of List
// Easy

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!(head -> next))
            return nullptr;
        ListNode* fast = head;
        for(int i = 0; i < n; i++) {
            fast = fast -> next;
        }
        if(!fast) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        ListNode* slow = head;
        while(fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* t = slow -> next;
        slow -> next = slow -> next -> next;
        delete t;
        return head;
    }
};
