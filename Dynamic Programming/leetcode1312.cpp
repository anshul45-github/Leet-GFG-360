#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
            return dp[i][j] = solve(s, i + 1, j - 1, dp);
        int ans1 = 1 + solve(s, i + 1, j, dp);
        int ans2 = 1 + solve(s, i, j - 1, dp);
        return dp[i][j] = min(ans1, ans2);
    }
public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return solve(s, 0, s.size() - 1, dp);
    }
};
