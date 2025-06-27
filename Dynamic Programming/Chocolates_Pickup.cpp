// https://www.geeksforgeeks.org/problems/chocolates-pickup/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 1}, {0, 1}, {1, 0}, {0, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
    int solveMem(vector<vector<int>>& grid, int n, int m, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
        if(i == n)
            return 0;
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return INT_MIN;
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int ans = 0;
        for(auto& direction : directions) {
            int y1 = j1 + direction[0];
            int y2 = j2 + direction[1];
            int go = solveMem(grid, n, m, i + 1, y1, y2, dp);
            if(j1 == j2)
                go += grid[i][j2];
            else
                go += grid[i][j1] + grid[i][j2];
            ans = max(ans, go);
        }
        return dp[i][j1][j2] = ans;
    }
    int solveTab(vector<vector<int>>& grid, int n, int m) {
        vector<vector<int>> next(m + 2, vector<int>(m + 2, 0));
        // for(int i = 0; i <= m + 1; i++) {
        //     for(int j = 0; j <= m + 1; j++)
        //         dp.back()[i][j] = 0;
        // }
        for(int i = n - 1; i >= 0; i--) {
            vector<vector<int>> curr(m + 2, vector<int>(m + 2, INT_MIN));
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    int ans = 0;
                    for(int d1 = -1; d1 <= 1; d1++) {
                        for(int d2 = -1; d2 <= 1; d2++) {
                            int y1 = j1 + d1;
                            int y2 = j2 + d2;
                            int go = next[y1 + 1][y2 + 1];
                            if(j1 == j2)
                                go += grid[i][j1];
                            else
                                go += grid[i][j1] + grid[i][j2];
                            ans = max(ans, go);
                        }
                    }
                    curr[j1 + 1][j2 + 1] = ans;
                }
            }
            next = curr;
        }
        return next[1][m];
    }
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));
        // return solveMem(grid, n, m, 0, 0, m - 1, dp);
        return solveTab(grid, n, m);
    }
};