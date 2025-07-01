// https://leetcode.com/problems/remove-outermost-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string newStr = "";
        int open = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                open++;
                if(open != 1)
                    newStr += s[i];
            }
            else {
                open--;
                if(open != 0)
                    newStr += s[i];
            }
        }
        return newStr;
    }
};