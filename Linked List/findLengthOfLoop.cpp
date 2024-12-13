#include<bits/stdc++.h>
using namespace std;

class Solution {
    int noOfNodesInLoop(Node* slow) {
        Node* temp = slow;
        temp = temp -> next;
        int n = 1;
        while(temp != slow) {
            n++;
            temp = temp -> next;
        }
        return n;
    }
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = slow -> next;
        while(fast && fast -> next) {
            if(slow == fast)
                return noOfNodesInLoop(slow);
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return 0;
    }
};
