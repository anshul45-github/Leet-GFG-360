// https://leetcode.com/problems/implement-stack-using-queues/
// 225. Implement Stack using Queues
// Easy

#include<queue>
using namespace std;

class MyStack {
    queue<int> q;
    int size;
public:
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        q.push(x);
        size++;
        for(int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        size--;
        return x;
    }
    
    int top() {
        return q.front();
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