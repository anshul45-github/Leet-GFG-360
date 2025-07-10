// https://leetcode.com/problems/dungeon-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& dungeons, int i, int j, vector<vector<int>>& dp) {
        if(i == dungeons.size() || j == dungeons[0].size())
            return INT_MAX;
        if(i == dungeons.size() - 1 && j == dungeons[0].size() -1)
            return (dungeons[i][j] <= 0) ? 1 - dungeons[i][j] : 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = min(solve(dungeons, i + 1, j, dp), solve(dungeons, i, j + 1, dp)) - dungeons[i][j];
        return dp[i][j] = (ans <= 0) ? 1 : ans;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size() + 1, vector<int>(dungeon[0].size() + 1, -1));
        return solve(dungeon, 0, 0, dp);
    }
};