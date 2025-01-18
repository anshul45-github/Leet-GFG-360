#include<bits/stdc++.h>
using namespace std;

class Solution {
    int len;
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if(i >= s1.size() || j >= s2.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        int i1 = i;
        int i2 = j;
        while(i < s1.size() && j < s2.size() && s1[i] == s2[j]) {
            ans++;
            i++;
            j++;
        }
        ans = max(ans, solve(s1, s2, i1 + 1, i2, dp));
        ans = max(ans, solve(s1, s2, i1, i2 + 1, dp));
        return dp[i1][i2] = ans;
    }
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return solve(s1, s2, 0, 0, dp);
    }
};
