// https://www.geeksforgeeks.org/problems/reverse-a-stack/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(stack<int>& st, int x) {
        if(st.empty()) {
            st.push(x);
            return;
        }
        int y = st.top();
        st.pop();
        helper(st, x);
        st.push(y);
    }
  public:
    void reverse(stack<int> &St) {
        if(St.empty())
            return;
        int x = St.top();
        St.pop();
        reverse(St);
        helper(St, x);
    }
};