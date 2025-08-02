// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode* next;
    
    StackNode(int x) {
        data = x;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        if(top == NULL) {
            top = new StackNode(x);
            return;
        }
        StackNode* newNode = new StackNode(x);
        newNode -> next = top;
        top = newNode;
        return;
    }

    int pop() {
        if(top == NULL)
            return -1;
        int x = top -> data;
        top = top -> next;
        return x;
    }

    MyStack() { top = NULL; }
};
