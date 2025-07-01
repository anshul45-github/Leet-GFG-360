// https://leetcode.com/problems/delete-node-in-a-linked-list/

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
        ListNode* prev;
        while(node -> next) {
            node -> val = node -> next -> val;
            prev = node;
            node = node -> next;
        }
        prev -> next = nullptr;
    }
};