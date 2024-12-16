#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        Node* copy = new Node(head -> val);
        Node* i = head;
        map<Node*, int> mp;
        int idx = 0;
        while(i) {
            mp[i] = idx;
            idx++;
            i = i -> next;
        }
        i = head;
        Node* j = copy;
        vector<Node*> v = {copy};
        while(i -> next) {
            j -> next = new Node(i -> next -> val);
            j = j -> next;
            v.push_back(j);
            i = i -> next;
        }
        i = head;
        j = copy;
        while(i) {
            j -> random = i -> random ? v[mp[i -> random]] : nullptr;
            j = j -> next;
            i = i -> next;
        }
        return copy;
    }
};
