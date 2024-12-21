#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        return;
    }
    
    int pop() {
        queue<int> q1;
        int peek;
        while(!q.empty()) {
            if(q.front() != q.back())
                q1.push(q.front());
            peek = q.front();
            q.pop();
        }
        while(!q1.empty()) {
            q.push(q1.front());
            q1.pop();
        }
        return peek;
    }
    
    int top() {
        queue<int> q1;
        int peek;
        while(!q.empty()) {
            q1.push(q.front());
            peek = q.front();
            q.pop();
        }
        while(!q1.empty()) {
            q.push(q1.front());
            q1.pop();
        }
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
