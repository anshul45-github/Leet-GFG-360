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
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        while(temp -> next -> next) {
            temp -> val = temp -> next -> val;
            temp = temp -> next;
        }
        temp -> val = temp -> next -> val;
        ListNode* temp2 = temp -> next;
        temp -> next = nullptr;
        delete temp2;
        return;
    }
};
