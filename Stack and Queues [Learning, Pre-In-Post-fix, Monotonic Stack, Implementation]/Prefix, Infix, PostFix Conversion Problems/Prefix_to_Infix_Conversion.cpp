// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        for(int i = pre_exp.size() - 1; i >= 0; i--) {
            if((pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || (pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || (pre_exp[i] >= '0' && pre_exp[i] <= '9')) {
                st.push(string(1, pre_exp[i]));
            }
            else {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                st.push("(" + a + string(1, pre_exp[i]) + b + ")");
            }
        }
        return st.top();
    }
};
