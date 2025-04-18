#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& s, int i, vector<int>& dp) {
        if(s[i] == '0')
            return 0;
        if(i >= s.size())
            return 0;
        if(i == s.size() - 1 || (i == s.size() - 2 && (s[i] == '1' || s[i] == '2') && s[i + 1] == '0'))
            return 1;
        if(i == s.size() - 2 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            return 2;
        if(dp[i] != -1)
            return dp[i];
        int total = solve(s, i + 1, dp);
        if(s[i] == '1')
            total += solve(s, i + 2, dp);
        if(s[i] == '2' && i + 1 < s.size() && s[i + 1] <= '6')
            total += solve(s, i + 2, dp);
        return dp[i] = total;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};
