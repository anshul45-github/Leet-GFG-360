// TC : O(N), SC : O(1)
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
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(fast) {
            slow = slow -> next;
        }
        ListNode* tail = reverseList(slow);
        while(tail) {
            if(head -> val != tail -> val)
                return false;
            head = head -> next;
            tail = tail -> next;
        }
        return true;
    }
};
