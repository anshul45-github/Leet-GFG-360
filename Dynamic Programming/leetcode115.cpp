#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        if(j == b.size())
            return 1;
        if(i == a.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(a[i] == b[j])
            return dp[i][j] = solve(a, b, i + 1, j + 1, dp) + solve(a, b, i + 1, j, dp);
        return dp[i][j] = solve(a, b, i + 1, j, dp);
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(s, t, 0, 0, dp);
    }
};
