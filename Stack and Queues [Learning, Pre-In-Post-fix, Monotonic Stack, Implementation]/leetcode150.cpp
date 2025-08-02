#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long op(string o, long long a, long long b) {
        if(o == "+")
            return a + b;
        if(o == "-")
            return b - a;
        if(o == "*")
            return a * b;
        return b / a;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] =="/") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                int x = op(tokens[i], a, b);
                st.push(x);
            }
            else
                st.push(stoi(tokens[i]) * 1LL);
        }
        return st.top();
    }
};