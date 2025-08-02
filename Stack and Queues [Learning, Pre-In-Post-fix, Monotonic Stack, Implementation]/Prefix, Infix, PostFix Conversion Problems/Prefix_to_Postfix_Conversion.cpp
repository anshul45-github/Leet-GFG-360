// https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        for(int i = pre_exp.size() - 1; i >= 0; i--) {
            char ch = pre_exp[i];
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
                st.push(string(1, ch));
            }
            else {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                st.push(a + b + string(1, ch));
            }
        }
        return st.top();
    }
};