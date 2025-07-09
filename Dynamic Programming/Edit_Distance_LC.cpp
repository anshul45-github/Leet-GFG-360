// https://leetcode.com/problems/edit-distance/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string& w1, string& w2, int i, int j) {
        if(i == w1.size())
            return w2.size() - j;
        if(j == w2.size())
            return w1.size() - i;
        int ans = INT_MAX;
        if(w1[i] == w2[j])
            return solve(w1, w2, i + 1, j + 1);
        else {
            ans = min(ans, 1 + solve(w1, w2, i + 1, j));
            ans = min(ans, 1 + solve(w1, w2, i + 1, j + 1));
            ans = min(ans, 1 + solve(w1, w2, i, j + 1));
        }
        return ans;
    }
    int solveMem(string& w1, string& w2, int i, int j, vector<vector<int>>& dp) {
        if(i == w1.size())
            return w2.size() - j;
        if(j == w2.size())
            return w1.size() - i;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        if(w1[i] == w2[j])
            return dp[i][j] = solveMem(w1, w2, i + 1, j + 1, dp);
        else {
            ans = min(ans, 1 + solveMem(w1, w2, i + 1, j, dp));
            ans = min(ans, 1 + solveMem(w1, w2, i + 1, j + 1, dp));
            ans = min(ans, 1 + solveMem(w1, w2, i, j + 1, dp));
        }
        return dp[i][j] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        // int ans = solve(word1, word2, 0, 0);

        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        int ans = solveMem(word1, word2, 0, 0, dp);

        return ans;
    }
};