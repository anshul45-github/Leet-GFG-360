// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

#include<bits/stdc++.h>
using namespace std;

class MyStack {
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

void MyStack ::push(int x) {
    top++;
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top == -1)
        return -1;
    top--;
    return arr[top + 1];
}