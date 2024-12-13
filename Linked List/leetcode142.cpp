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
    ListNode* getCycleRoot(ListNode* head, ListNode* slow) {
        ListNode* s2 = head;
        while(slow != s2) {
            slow = slow -> next;
            s2 = s2 -> next;
        }
        return slow;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
        if(!(head -> next))
            return nullptr;
        ListNode* slow = head -> next;
        ListNode* fast = head -> next -> next;
        while(slow && fast && fast -> next) {
            if(slow == fast)
                return getCycleRoot(head, slow);
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return nullptr;
    }
};
