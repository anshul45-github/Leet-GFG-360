// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Recursive approach - TLE
    int solve(vector<int>& prices, int idx, bool buy) {
        if(idx == prices.size())
            return 0;
        int profit;
        if(buy) {
            profit = max(solve(prices, idx + 1, 0) - prices[idx], solve(prices, idx + 1, 1));
        }
        else {
            profit = max(solve(prices, idx + 1, 1) + prices[idx], solve(prices, idx + 1, 0));
        }
        return profit;
    }

    // Memoization approach - Fastest in Dynamic Programming
    int solveMem(vector<int>& prices, int idx, bool buy, vector<vector<int>>& dp) {
        if(idx == prices.size())
            return 0;
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        int profit;
        if(buy) {
            profit = max(solveMem(prices, idx + 1, 0, dp) - prices[idx], solveMem(prices, idx + 1, 1, dp));
        }
        else {
            profit = max(solveMem(prices, idx + 1, 1, dp) + prices[idx], solveMem(prices, idx + 1, 0, dp));
        }
        return dp[idx][buy] = profit;
    }

    // Tabulation approach
    int solveTab(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        for(int i = prices.size() - 1; i >= 0; i--) {
            for(int j = 0; j < 2; j++) {
                if(j)
                    dp[i][j] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
                else
                    dp[i][j] = max(dp[i + 1][1] + prices[i], dp[i + 1][0]);
            }
        }
        return dp[0][1];
    }

    // Space Optimization approach - Least Memory Usage in Dynamic Programming
    int spaceOptimization(vector<int>& prices) {
        vector<int> next(2, 0);
        for(int i = prices.size() - 1; i >= 0; i--) {
            vector<int> curr(2);
            for(int j = 0; j < 2; j++) {
                if(j)
                    curr[j] = max(next[0] - prices[i], next[1]);
                else
                    curr[j] = max(next[1] + prices[i], next[0]);
            }
            next = curr;
        }
        return next[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        // int ans = solve(prices, 0, 1);

        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // int ans = solveMem(prices, 0, 1, dp);

        // int ans = solveTab(prices);

        int ans = spaceOptimization(prices);

        return ans;
    }
};

// Greedy approach - O(n) time complexity and O(1) space complexity (Fastest and least memory usage approac).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int n = prices.size();
        int maxProfit = 0;
        for(int i = 1; i < n; i++) {
            minVal = min(minVal, prices[i]);
            maxProfit += prices[i] - minVal;
            if(prices[i] - minVal > 0)
                minVal = prices[i];
        }
        return maxProfit;
    }
};