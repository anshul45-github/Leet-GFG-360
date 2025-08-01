// https://leetcode.com/problems/string-to-integer-atoi/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& s, int i, int currNum, bool sign) {
        if(i == s.size())
            return currNum;
        if(s[i] >= '0' && s[i] <= '9') {
            if(sign) {
                if(currNum <= (INT_MAX - (s[i] - '0')) / 10)
                    currNum = currNum * 10 + (s[i] - '0');
                else
                    return INT_MAX;
            }
            else if(!sign) {
                if(currNum >= (INT_MIN + (s[i] - '0')) / 10)
                    currNum = currNum * 10 - (s[i] - '0');
                else
                    return INT_MIN;
            }
            return solve(s, i + 1, currNum, sign);
        }
        return currNum;
    }
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ')
            i++;
        bool sign = true;
        if(s[i] == '+')
            i++;
        else if(s[i] == '-') {
            sign = false;
            i++;
        }
        return solve(s, i, 0, sign);
    }
};