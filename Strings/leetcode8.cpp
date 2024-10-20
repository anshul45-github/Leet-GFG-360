#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ')
            i++;
        int c = 0;
        bool neg = false;
        if(s[i] == '-') {
            neg = true;
            i++;
        }
        else if(s[i] == '+')
            i++;
        while(i < s.size()) {
            if(s[i] <= '9' && s[i] >= '0') {
                if(c > (INT_MAX - (s[i] - '0')) / 10) {
                    if(neg)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }
                c = c*10 + (s[i] - '0');
            }
            else
                break;
            i++;
        }
        if(neg)
            c *= -1;
        return c;
    }
};
