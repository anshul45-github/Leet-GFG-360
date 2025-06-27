// https://leetcode.com/problems/delete-operation-for-two-strings/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if(i == s1.size())
            return s2.size() - j;
        if(j == s2.size())
            return s1.size() - i;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = solve(s1, s2, i + 1, j + 1, dp);
        return dp[i][j] = min(solve(s1, s2, i + 1, j, dp), solve(s1, s2, i, j + 1, dp)) + 1;
    }
public:
    int minDistance(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solve(s1, s2, 0, 0, dp);
    }
};