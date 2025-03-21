struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* t = head;
        ListNode* n = nullptr;
        while(t) {
            ListNode* temp = t -> next;
            t -> next = n;
            n = t;
            t = temp;
        }
        return n;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* next = slow -> next;
        slow -> next = nullptr;
        ListNode* secondHalf = reverseList(next);
        ListNode* temp1 = head;
        ListNode* temp2 = secondHalf;
        while(temp1) {
            ListNode* t = temp1 -> next;
            temp1 -> next = temp2;
            temp1 = temp1 -> next;
            temp2 = t;
        }
        return;
    }
};