// Using only one queue
#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;
    void reverseStack(int& peek) {
        if(q.empty())
            return;
        if(q.front() == q.back()) {
            peek = q.front();
            return;
        }
        int x = q.front();
        q.pop();
        reverseStack(peek);
        q.push(x);
    }
    void popHelper(int& peek) {
        if(q.front() == q.back()) {
            peek = q.front();
            q.pop();
            return;
        }
        int x = q.front();
        q.pop();
        popHelper(peek);
        q.push(x);
        return;
    }
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        return;
    }
    
    int pop() {
        int x;
        popHelper(x);
        int r;
        reverseStack(r);
        return x;
    }
    
    int top() {
        int peek;
        reverseStack(peek);
        int x;
        reverseStack(x);
        return peek;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
