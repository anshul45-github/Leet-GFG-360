#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& t1, string& t2, int i, int j, vector<vector<int>>& dp) {
        if(i == t1.size() || j == t2.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(t1[i] == t2[j])
            return 1 + solve(t1, t2, i + 1, j + 1, dp);
        int ans1 = solve(t1, t2, i + 1, j, dp);
        int ans2 = solve(t1, t2, i, j + 1, dp);
        return dp[i][j] = max(ans1, ans2);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
