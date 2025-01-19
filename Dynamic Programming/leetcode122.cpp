#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& dp) {
        if(i == prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int take = 0;
        if(buy)
            take = -prices[i] + solve(prices, i + 1, false, dp);
        else
            take = prices[i] + solve(prices, i + 1, true, dp);
        int notTake = solve(prices, i + 1, buy, dp);
        return dp[i][buy] = max(take, notTake);
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, true, dp);
    }
};
