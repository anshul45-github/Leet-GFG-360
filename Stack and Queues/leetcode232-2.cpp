// Amortized time complexity for each operation : O(1)
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> ip;
    stack<int> op;
public:
    MyQueue() {}
    
    void push(int x) {
        ip.push(x);
        return;
    }
    
    int pop() {
        int k = peek();
        op.pop();
        return k;
    }
    
    int peek() {
        if(op.empty()) {
            while(!ip.empty()) {
                op.push(ip.top());
                ip.pop();
            }
        }
        return op.top();
    }
    
    bool empty() {
        return ip.empty() && op.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
