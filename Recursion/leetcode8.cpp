#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string s, int i, int sum, bool neg) {
        if(i == s.size() || s[i] < '0' || s[i] > '9')
            return sum;
        int digit = s[i] - '0';
        digit = neg ? -digit : digit;
        if(neg && (INT_MIN - digit) / 10 > sum)
            return INT_MIN;
        if(!neg && (INT_MAX - digit) / 10 < sum)
            return INT_MAX;
        sum = (sum * 10) + digit;
        return solve(s, i + 1, sum, neg);
    }
public:
    int myAtoi(string s) {
        int idx = 0;
        bool neg = false;
        while(s[idx] == ' ')
            idx++;
        if(s[idx] == '+')
            idx++;
        else if(s[idx] == '-') {
            neg = true;
            idx++;
        }
        int ans = solve(s, idx, 0, neg);
        return ans;
    }
};
