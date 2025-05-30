#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        if(i == a.size())
            return b.size() - j;
        if(j == b.size())
            return a.size() - i;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(a[i] == b[j])
            return dp[i][j] = solve(a, b, i + 1, j + 1, dp);
        int ans1 = 1 + solve(a, b, i + 1, j, dp);
        int ans2 = 1 + solve(a, b, i, j + 1, dp);
        return dp[i][j] = min(ans1, ans2);
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
