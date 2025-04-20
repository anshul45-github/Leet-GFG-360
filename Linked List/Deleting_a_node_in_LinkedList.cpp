// https://leetcode.com/problems/delete-node-in-a-linked-list/description/
// 237. Delete Node in a Linked List
// Medium

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        while(temp -> next && temp -> next -> next) {
            temp -> val = temp -> next -> val;
            temp = temp -> next;
        }
        temp -> val = temp -> next -> val;
        temp -> next = nullptr;
        return;
    }
};