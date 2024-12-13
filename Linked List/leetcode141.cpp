#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while(slow && fast && fast -> next) {
            if(slow == fast)
                return true;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return false;
    }
};
