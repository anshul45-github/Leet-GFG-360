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
    ListNode* reverse(ListNode* head, ListNode* curr, ListNode* prev, int no) {
        ListNode* p = curr;
        for(int i = 0; i < no; i++) {
            p = p -> next;
        }
        ListNode* n = curr -> next;
        for(int i = 0; i < no; i++) {
            curr -> next = p;
            p = curr;
            if(i != no - 1)
                curr = n;
            if(n)
                n = n -> next;
        }
        if(prev)
            prev -> next = curr;
        return curr;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        vector<int> v;
        ListNode* curr = head;
        int size = 0;
        while(curr) {
            size++;
            curr = curr -> next;
        }
        k = k % size;
        if(k == 0)
            return head;
        curr = head;
        ListNode* newHead = reverse(head, curr, nullptr, size);
        newHead = reverse(head, newHead, nullptr, k);
        curr = newHead;
        for(int i = 0; i < k - 1; i++)
            curr = curr -> next;
        reverse(head, curr -> next, curr, size - k);
        return newHead;
    }
};
