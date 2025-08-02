// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string> st;
        for(int i = 0; i < post_exp.size(); i++) {
            char ch = post_exp[i];
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
                st.push(string (1, ch));
            }
            else {
                string b = st.top();
                st.pop();
                string a = st.top();
                st.pop();
                st.push(string(1, ch) + a + b);
            }
        }
        return st.top();
    }
};
