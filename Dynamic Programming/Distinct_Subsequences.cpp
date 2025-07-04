// https://leetcode.com/problems/distinct-subsequences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if(j == t.size())
            return 1;
        if(i == s.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = solve(s, t, i + 1, j, dp);
        if(s[i] == t[j])
            ans += solve(s, t, i + 1, j + 1, dp);
        return dp[i][j] = ans;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return solve(s, t, 0, 0, dp);
    }
};