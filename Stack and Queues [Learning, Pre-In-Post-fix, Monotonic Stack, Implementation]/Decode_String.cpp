// https://leetcode.com/problems/decode-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isNum(char ch) {
        return ch >= '0' && ch <= '9';
    }
    bool isAlpha(char ch) {
        return ch >= 'a' && ch <= 'z';
    }
    string repeat(string& str, int n) {
        string ans = "";
        for(int i = 0; i < n; i++)
            ans += str;
        return ans;
    }
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i = 0; i < s.size(); i++) {
            if(isNum(s[i])) {
                int start = i;
                while(isNum(s[i]))
                    i++;
                st.push(s.substr(start, i - start));
                i--;
            }
            else if(isAlpha(s[i])) {
                int start = i;
                while(isAlpha(s[i]))
                    i++;
                st.push(s.substr(start, i - start));
                i--;
            }
            else if(s[i] == '[') 
                st.push(string(1, s[i]));
            else {
                string str = "";
                while(isAlpha(st.top()[0])) {
                    str = st.top() + str;
                    st.pop();
                }
                // st.pop();
                st.pop();
                int n = stoi(st.top());
                st.pop();
                st.push(repeat(str, n));
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};