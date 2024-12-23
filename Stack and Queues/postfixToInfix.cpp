#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;
        for(int i = 0; i < exp.size(); i++) {
            if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
                st.push(string(1, exp[i]));
            else if(exp[i] == '^' || exp[i] == '/' || exp[i] == '-') {
                string b = st.top();
                st.pop();
                string a = st.top();
                st.pop();
                st.push("(" + a + string(1, exp[i]) + b + ")");
            }
            else {
                string b = st.top();
                st.pop();
                string a = st.top();
                st.pop();
                st.push("(" + a + string(1, exp[i]) + b + ")");
            }
        }
        return st.top();
    }
};
