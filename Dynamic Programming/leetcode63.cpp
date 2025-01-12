#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if(i == grid.size() || j == grid[0].size() || grid[i][j] == 1)
            return 0;
        if(i == grid.size() - 1 && j == grid[0].size() - 1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = solve(grid, i + 1, j, dp) + solve(grid, i, j + 1, dp);
        return dp[i][j] = ans;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, 0, 0, dp);
    }
};
