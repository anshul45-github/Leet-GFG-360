// https://leetcode.com/problems/odd-even-linked-list/
// 328. Odd Even Linked List
// Medium

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* o = odd;
        ListNode* e = even;
        while(odd && odd -> next && even && even -> next) {
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;
            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = e;
        return o;
    }
};
