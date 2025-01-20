#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& dp, int& fee) {
        if(i == prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int take = 0;
        if(buy)
            take = -prices[i] + solve(prices, i + 1, false, dp, fee);
        else
            take = prices[i] + solve(prices, i + 1, true, dp, fee) - fee;
        int notTake = solve(prices, i + 1, buy, dp, fee);
        return dp[i][buy] = max(take, notTake);
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, true, dp, fee);
    }
};
