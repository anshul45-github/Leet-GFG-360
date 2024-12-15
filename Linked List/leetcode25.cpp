// SC : O(1)
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
    bool reverse(ListNode* head, ListNode* curr, ListNode* prev, int k) {
        ListNode* p = curr;
        for(int i = 0; i < k; i++) {
            if(!p)
                return false;
            p = p -> next;
        }
        ListNode* n = curr -> next;
        for(int i = 0; i < k; i++) {
            curr -> next = p;
            p = curr;
            if(i != k - 1)
                curr = n;
            if(n)
                n = n -> next;
        }
        if(prev)
            prev -> next = curr;
        return true;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        for(int i = 1; i < k; i++) {
            head = head -> next;
        }
        while(curr) {
            bool a = reverse(head, curr, prev, k);
            if(!a)
                return head;
            prev = curr;
            curr = curr -> next;
        }
        return head;
    }
};
