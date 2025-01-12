#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& matrix, int i, int j1, int j2, vector<vector<int>>& dir, vector<vector<vector<int>>>& dp) {
        if(j1 < 0 || j1 == matrix[0].size() || j2 < 0 || j2 == matrix[0].size())
            return INT_MIN;
        if(i == matrix.size())
            return 0;
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int ans = INT_MIN;
        for(int k = 0; k < 9; k++) {
            if(j1 == j2)
                ans = max(ans, solve(matrix, i + 1, j1 + dir[k][0], j2 + dir[k][1], dir, dp) + matrix[i][j1]);
            else
                ans = max(ans, solve(matrix, i + 1, j1 + dir[k][0], j2 + dir[k][1], dir, dp) + matrix[i][j1] + matrix[i][j2]);
        }
        return dp[i][j1][j2] = ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {0, 0}, {1, 1}, {1, -1}, {1, 0}};
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return solve(grid, 0, 0, grid[0].size() - 1, directions, dp);
    }
};
