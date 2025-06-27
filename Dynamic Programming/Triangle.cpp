// https://leetcode.com/problems/triangle/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& triangle, int idx, int col, vector<vector<int>>& dp) {
        if(idx == triangle.size())
            return 0;
        if(dp[idx][col] != -1)
            return dp[idx][col];
        int ans = min(solve(triangle, idx + 1, col, dp), solve(triangle, idx + 1, col + 1, dp)) + triangle[idx][col];
        return dp[idx][col] = ans;
    }
    int solveTab(vector<vector<int>>& triangle) {
        vector<int> next(triangle[triangle.size() - 1].size() + 1, 0);
        vector<int> curr(triangle[triangle.size() - 1].size() + 1, 0);
        for(int i = triangle.size() - 1; i >= 0; i--) {
            for(int col = triangle[i].size() - 1; col >= 0; col--) {
                curr[col] = min(next[col], next[col + 1]) + triangle[i][col];
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));
        // return solve(triangle, 0, 0, dp);
        return solveTab(triangle);
    }
};