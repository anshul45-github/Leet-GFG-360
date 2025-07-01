// https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; 

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        Node* temp = head;
        int cnt = 0;
        while(temp) {
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
};