#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getPriority(char c) {
        if(c == '^')
            return 3;
        if(c == '*' || c == '/')
            return 2;
        if(c == '+' || c == '-')
            return 1;
        return 0;
    }
  public:
    string convert(string s) {
        stack<char> op;
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                ans += s[i];
            else {
                if(s[i] == '(')
                    op.push(s[i]);
                else if(s[i] == ')') {
                    while(!op.empty() && op.top() != '(') {
                        char next = op.top();
                        op.pop();
                        ans += next;
                    }
                    op.pop();
                }
                else {
                    while(!op.empty() && getPriority(s[i]) <= getPriority(op.top())) {
                        ans += op.top();
                        op.pop();
                    }
                    op.push(s[i]);
                }
            }
        }
        while(!op.empty()) {
            ans += op.top();
            op.pop();
        }
        return ans;
    }
    string infixToPostfix(string& s) {
        return convert(s);
    }
};
