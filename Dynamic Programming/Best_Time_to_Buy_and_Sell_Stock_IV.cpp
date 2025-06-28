// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Recursive approach - TLE
    int solve(vector<int>& prices, int k, int operationNo, int index) {
        if(index == prices.size())
            return 0;
        if(operationNo == 2 * k)
            return 0;
        int profit;
        if(operationNo % 2 == 0)
            profit = max(solve(prices, k, operationNo + 1, index + 1) - prices[index], solve(prices, k, operationNo, index + 1));
        else
            profit = max(solve(prices, k, operationNo + 1, index + 1) + prices[index], solve(prices, k, operationNo, index + 1));
        return profit;
    }

    // Memoization approach
    int solveMem(vector<int>& prices, int k, int operationNo, int index, vector<vector<int>>& dp) {
        if(index == prices.size())
            return 0;
        if(operationNo == 2 * k)
            return 0;
        if(dp[index][operationNo] != -1)
            return dp[index][operationNo];
        int profit;
        if(operationNo % 2 == 0)
            profit = max(solveMem(prices, k, operationNo + 1, index + 1, dp) - prices[index], solveMem(prices, k, operationNo, index + 1, dp));
        else
            profit = max(solveMem(prices, k, operationNo + 1, index + 1, dp) + prices[index], solveMem(prices, k, operationNo, index + 1, dp));
        return dp[index][operationNo] = profit;
    }

    // Tabulation approach
    int solveTab(vector<int>& prices, int k) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>((2 * k) + 1, 0));
        for(int i = prices.size() - 1; i >= 0; i--) {
            for(int j = (2 * k) - 1; j >= 0; j--) {
                if(j % 2 == 0)
                    dp[i][j] = max(dp[i + 1][j + 1] - prices[i], dp[i + 1][j]);
                else
                    dp[i][j] = max(dp[i + 1][j + 1] + prices[i], dp[i + 1][j]);
            }
        }
        return dp[0][0];
    }

    // Space Optimization approach
    int spaceOptimization(vector<int>& prices, int k) {
        // vector<vector<int>> dp(prices.size() + 1, vector<int>((2 * k) + 1, 0));
        vector<int> next(2 * k + 1, 0);
        for(int i = prices.size() - 1; i >= 0; i--) {
            vector<int> curr(2 * k + 1, 0);
            for(int j = (2 * k) - 1; j >= 0; j--) {
                if(j % 2 == 0)
                    curr[j] = max(next[j + 1] - prices[i], next[j]);
                else
                    curr[j] = max(next[j + 1] + prices[i], next[j]);
            }
            next = curr;
        }
        return next[0];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        // int ans = solve(prices, k, 0, 0);

        // vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));
        // int ans = solveMem(prices, k, 0, 0, dp);

        // int ans = solveTab(prices, k);

        int ans = spaceOptimization(prices, k);

        return ans;
    }
};