#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
            return dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);
        return dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int ans = solve(s, 0, s.size() - 1, dp);

        return ans;
    }
};
