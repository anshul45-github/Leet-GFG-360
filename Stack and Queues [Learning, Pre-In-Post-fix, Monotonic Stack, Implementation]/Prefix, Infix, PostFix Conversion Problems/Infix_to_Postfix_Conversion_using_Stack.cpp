// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int prec(char ch) {
        if(ch == '(')
            return -1;
        if(ch == '^')
            return 2;
        if(ch == '*' || ch == '/')
            return 1;
        return 0;
    }
  public:
    string infixToPostfix(string& s) {
        string newStr = "";
        stack<char> ops;
        for(char ch : s) {
            if(ch == '(') 
                ops.push(ch);
            else if(ch == ')') {
                while(ops.top() != '(') {
                    newStr += ops.top();
                    ops.pop();
                }
                ops.pop();
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
                while(!ops.empty() && prec(ops.top()) >= prec(ch)) {
                    newStr += ops.top();
                    ops.pop();
                }
                ops.push(ch);
            }
            else
                newStr += ch;
        }
        while(!ops.empty()) {
            newStr += ops.top();
            ops.pop();
        }
        return newStr;
    }
};