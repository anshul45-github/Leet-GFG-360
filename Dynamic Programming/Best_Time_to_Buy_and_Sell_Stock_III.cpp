// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices, int i, int opNo, vector<vector<int>>& dp) {
        if(i == prices.size() || opNo == 4)
            return 0;
        if(dp[i][opNo] != -1)
            return dp[i][opNo];
        int ans = solve(prices, i + 1, opNo, dp);
        if(opNo & 1)
            ans = max(ans, solve(prices, i + 1, opNo + 1, dp) + prices[i]);
        else
            ans = max(ans, solve(prices, i + 1, opNo + 1, dp) - prices[i]);
        return dp[i][opNo] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(4, -1));
        return solve(prices, 0, 0, dp);
    }
};