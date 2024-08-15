#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')' && st.empty())
                st.push(s[i]);
            else if(s[i] == ')' && st.top() == '(')
                st.pop();
            else if(s[i] == ')')
                st.push(s[i]);
        }
        return st.size();
    }
};
