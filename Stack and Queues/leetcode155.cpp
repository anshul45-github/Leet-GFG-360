#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    int mini;
    Node* next;
    Node(int val, int mini, Node* next) {
        this -> val = val;
        this -> mini = mini;
        this -> next = next;
    }
};

class MinStack {
    Node* head;
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if(!head) {
            head = new Node(val, val, nullptr);
            return;
        }
        head = new Node(val, min(val, head -> mini), head);
    }
    
    void pop() {
        head = head -> next;
    }
    
    int top() {
        return head -> val;
    }
    
    int getMin() {
        return head -> mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
