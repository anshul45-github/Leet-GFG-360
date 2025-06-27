// https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if(i == grid.size() || j == grid[0].size())
            return 1e9;
        if(i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = min(solve(grid, i + 1, j, dp), solve(grid, i, j + 1, dp)) + grid[i][j];
        return dp[i][j] = ans;
    }
    int solveTab(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 1e9));
        vector<int> next(grid[0].size() + 1, 1e9);
        vector<int> curr(grid[0].size() + 1, 1e9);
        curr[grid[0].size() - 1] = grid[grid.size() - 1][grid[0].size() - 1];
        // dp[grid.size() - 1][grid[0].size() - 1] = grid[grid.size() - 1][grid[0].size() - 1];
        for(int i = grid.size() - 1; i >= 0; i--) {
            for(int j = grid[0].size() - 1; j >= 0; j--) {
                if(i == grid.size() - 1 && j == grid[0].size() - 1)
                    continue;
                curr[j] = min(next[j], curr[j + 1]) + grid[i][j];
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // return solve(grid, 0, 0, dp);
        return solveTab(grid);
    }
};