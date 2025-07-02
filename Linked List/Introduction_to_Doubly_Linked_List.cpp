// https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& nums) {
        Node* head = new Node(nums.back());
        for(int i = nums.size() - 2; i >= 0; i--) {
            head -> prev = new Node(nums[i]);
            head -> prev -> next = head;
            head = head -> prev;
        }
        return head;
    }
};