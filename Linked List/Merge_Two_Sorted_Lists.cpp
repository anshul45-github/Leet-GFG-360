// https://leetcode.com/problems/merge-two-sorted-lists/
// Easy

// Merge two sorted linked lists and return it as a new sorted list.

// The new list should be made by splicing together the nodes of the first two lists.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

// Constraints:
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100

// Time complexity: O(n + m), where n and m are the lengths of the two linked lists.
// Space complexity: O(1), since we are not using any extra space for the output list.

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1 -> val > list2 -> val)
            return mergeTwoLists(list2, list1);
        ListNode* head = list1;
        ListNode* temp = head;
        ListNode* temp1 = list1 -> next;
        ListNode* temp2 = list2;
        while(temp1 && temp2) {
            if(temp1 -> val < temp2 -> val) {
                temp -> next = temp1;
                temp1 = temp1 -> next;
            }
            else {
                temp -> next = temp2;
                temp2 = temp2 -> next;
            }
            temp = temp -> next;
        }
        if(temp1)
            temp -> next = temp1;
        if(temp2)
            temp -> next = temp2;
        return head;
    }
};