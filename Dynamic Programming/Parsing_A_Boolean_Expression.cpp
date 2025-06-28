// https://leetcode.com/problems/parsing-a-boolean-expression/

#include <bits/stdc++.h>
using namespace std;

// Using Single Stack Approach
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char currChar : expression) {
            if(currChar == ',' || currChar == '(')
                continue;  
            if(currChar == 't' || currChar == 'f' || currChar == '!' || currChar == '&' || currChar == '|') 
                st.push(currChar);         
            else if(currChar == ')') {
                bool hasTrue = false, hasFalse = false;
                while(st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topValue = st.top();
                    st.pop();
                    if(topValue == 't') 
                        hasTrue = true;
                    if(topValue == 'f') 
                        hasFalse = true;
                }
                char op = st.top();
                st.pop();
                if(op == '!') 
                    st.push(hasTrue ? 'f' : 't');
                else if(op == '&') 
                    st.push(hasFalse ? 'f' : 't');
                else 
                    st.push(hasTrue ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};

// Using Two Stacks Approach
class Solution {
    char evaluateAnd(stack<char>& operands) {
        char ans = 't';
        while(operands.top() != '(') {
            if(operands.top() == 'f') {
                ans = 'f';
                break;
            }
            operands.pop();
        }
        while(operands.top() != '(')
            operands.pop();
        operands.pop();
        return ans;
    }
    char evaluateOr(stack<char>& operands) {
        char ans = 'f';
        while(operands.top() != '(') {
            if(operands.top() == 't') {
                ans = 't';
                break;
            }
            operands.pop();
        }
        while(operands.top() != '(')
            operands.pop();
        operands.pop();
        return ans;
    }
    char evaluateNot(stack<char>& operands) {
        char ans = 't';
        if(operands.top() == 't')
            ans = 'f';
        operands.pop();
        operands.pop();
        return ans;
    }
public:
    bool parseBoolExpr(string expression) {
        stack<char> operands;
        stack<char> operators;
        for(char ch : expression) {
            if(ch == ')') {
                char op = operators.top();
                if(op == '&')
                    operands.push(evaluateAnd(operands));
                else if(op == '|')
                    operands.push(evaluateOr(operands));
                else
                    operands.push(evaluateNot(operands));
                operators.pop();
            }
            else if(ch == '&' || ch == '|' || ch == '!')
                operators.push(ch);
            else if(ch != ',')
                operands.push(ch);
            
        }
        return operands.top() == 't';
    }
};