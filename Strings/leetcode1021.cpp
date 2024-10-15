#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string str;
        int open = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                open++;
                if(open == 1)
                    continue;
            }
            if(s[i] == ')') {
                open--;
                if(open == 0) {
                    continue;
                }
            }
            if(i != 0)
                str += s[i];
        }
        return str;
    }
};
