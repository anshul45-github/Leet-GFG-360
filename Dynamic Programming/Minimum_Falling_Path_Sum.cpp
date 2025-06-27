// https://leetcode.com/problems/minimum-falling-path-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if(i == matrix.size())
            return 0;
        if(j < 0 || j == matrix[i].size())
            return 1e9;
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        int goLeft = solve(matrix, i + 1, j - 1, dp);
        int goStraight = solve(matrix, i + 1, j, dp);
        int goRight = solve(matrix, i + 1, j + 1, dp);
        return dp[i][j] = min(min(goLeft, goStraight), goRight) + matrix[i][j];
    }
    int solveTab(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        for(int i = 0; i <= n; i++)
            dp.back()[i] = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(j >= 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                dp[i][j] = min(min(dp[i][j], dp[i + 1][j]), dp[i + 1][j + 1]);
                dp[i][j] += matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
            ans = min(ans, dp[0][i]);
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, INT_MAX));
        // int ans = INT_MAX;
        // for(int i = 0; i < matrix.size(); i++) 
        //     ans = min(ans, solve(matrix, 0, i, dp));
        //     // i = max(i + 2, min(i + 3, (int)matrix.size() - 1))
        // return ans;
        return solveTab(matrix);
    }
};