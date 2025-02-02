#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<bool> st;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                st.push(0);
            if(s[i] == ')') {
                if(st.empty())
                    ans++;
                else
                    st.pop();
            }
        }
        ans += st.size();
        return ans;
    }
};
