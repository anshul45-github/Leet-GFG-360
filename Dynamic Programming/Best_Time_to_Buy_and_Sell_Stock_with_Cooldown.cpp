// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices, int i, bool op, vector<vector<int>>& dp) {
        if(i >= prices.size())
            return 0;
        if(dp[i][op] != -1)
            return dp[i][op];
        int ans = solve(prices, i + 1, op, dp);
        if(op)
            ans = max(ans, solve(prices, i + 2, !op, dp) + prices[i]);
        else
            ans = max(ans, solve(prices, i + 1, !op, dp) - prices[i]);
        return dp[i][op] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return solve(prices, 0, 0, dp);
    }
};