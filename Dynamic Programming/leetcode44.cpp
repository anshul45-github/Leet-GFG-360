#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if(i == s.size() && j == p.size())
            return true;
        if(j == p.size())
            return false;
        if(i == s.size()) {
            for(int k = j; k < p.size(); k++) {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
        else if(p[j] == '*')
            return dp[i][j] = solve(s, p, i + 1, j, dp) || solve(s, p, i, j + 1, dp);
        dp[i][j] = 0;
        return false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return solve(s, p, 0, 0, dp);
    }
};
