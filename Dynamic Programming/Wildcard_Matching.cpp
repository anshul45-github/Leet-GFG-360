// https://leetcode.com/problems/wildcard-matching/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(string str, string pattern, int i, int j) {
        if(i < 0 && j < 0)
            return true;
        if(i >= 0 && j < 0)
            return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(pattern[k] != '*')
                    return false;
            }
            return true;
        }
        if(str[i] == pattern[j] || pattern[j] == '?')
            return solve(str, pattern, i - 1, j - 1);
        else if(pattern[j] == '*')
            return solve(str, pattern, i - 1, j) || solve(str, pattern, i, j - 1);
        return false;
    }
    bool solveMem(string str, string pattern, int i, int j, vector<vector<int>>& dp) {
        if(i < 0 && j < 0)
            return true;
        if(i >= 0 && j < 0)
            return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(pattern[k] != '*')
                    return false;
            }
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(str[i] == pattern[j] || pattern[j] == '?')
            return dp[i][j] = solveMem(str, pattern, i - 1, j - 1, dp);
        else if(pattern[j] == '*')
            return dp[i][j] = solveMem(str, pattern, i - 1, j, dp) || solveMem(str, pattern, i, j - 1, dp);
        return dp[i][j] = false;
    }
    int solveTab(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[0][0] = 1;
        for(int j = 1; j <= p.size(); j++) {
            dp[0][j] = 1;
            for(int k = 0; k < j; k++) {
                if(p[k] != '*') {
                    dp[0][j] = 0;
                    break;
                }
            }
        }
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[s.size()][p.size()];
    }
    int spaceOptimization(string s, string p) {
        vector<int> prev(p.size() + 1, 0);
        vector<int> curr(p.size() + 1, 0);
        prev[0] = 1;
        for(int j = 1; j <= p.size(); j++) {
            prev[j] = 1;
            for(int k = 0; k < j; k++) {
                if(p[k] != '*') {
                    prev[j] = 0;
                    break;
                }
            }
        }
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if(p[j - 1] == '*')
                    curr[j] = prev[j] || curr[j - 1];
                else
                    curr[j] = 0;
            }
            prev = curr;
        }
        return prev[p.size()];
    }
public:
    bool isMatch(string s, string p) {
        // bool ans = solve(s, p, s.size() - 1, p.size() - 1);

        // vector<vector<int>> dp(s.size(), vector<int>(p.size(), - 1));
        // bool ans = solveMem(s, p, s.size() - 1, p.size() - 1, dp);

        // bool ans = solveTab(s, p);

        bool ans = spaceOptimization(s, p);

        return ans;
    }
};