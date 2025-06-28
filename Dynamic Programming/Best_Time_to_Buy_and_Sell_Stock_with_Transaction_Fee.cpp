// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices, int idx, bool buy, int fee) {
        if(idx == prices.size())
            return 0;
        int profit;
        if(buy) {
            profit = max(solve(prices, idx + 1, 0, fee) - prices[idx], solve(prices, idx + 1, 1, fee));
        }
        else {
            profit = max(solve(prices, idx + 1, 1, fee) + prices[idx] - fee, solve(prices, idx + 1, 0, fee));
        }
        return profit;
    }
    int solveMem(vector<int>& prices, int idx, bool buy, int fee, vector<vector<int>>& dp) {
        if(idx == prices.size())
            return 0;
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        int profit;
        if(buy) {
            profit = max(solveMem(prices, idx + 1, 0, fee, dp) - prices[idx], solveMem(prices, idx + 1, 1, fee, dp));
        }
        else {
            profit = max(solveMem(prices, idx + 1, 1, fee, dp) + prices[idx] - fee, solveMem(prices, idx + 1, 0, fee, dp));
        }
        return dp[idx][buy] = profit;
    }
    int solveTab(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        for(int i = prices.size() - 1; i >= 0; i--) {
            for(int j = 0; j < 2; j++) {
                int profit;
                if(j)
                    profit = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
                else
                    profit = max(dp[i + 1][1] + prices[i] - fee, dp[i + 1][0]);
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
    int spaceOptimization(vector<int>& prices, int fee) {
        vector<int> next(2, 0);
        for(int i = prices.size() - 1; i >= 0; i--) {
            vector<int> curr(2);
            for(int j = 0; j < 2; j++) {
                int profit;
                if(j)
                    profit = max(next[0] - prices[i], next[1]);
                else
                    profit = max(next[1] + prices[i] - fee, next[0]);
                curr[j] = profit;
            }
            next = curr;
        }
        return next[1];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        // int ans = solve(prices, 0, 1, fee);

        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // int ans = solveMem(prices, 0, 1, fee, dp);

        // int ans = solveTab(prices, fee);

        int ans = spaceOptimization(prices, fee);

        return ans;
    }
};