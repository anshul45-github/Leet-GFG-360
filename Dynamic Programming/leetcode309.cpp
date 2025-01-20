#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices, int i, bool buy, bool last, vector<vector<vector<int>>>& dp) {
        if(i == prices.size())
            return 0;
        if(dp[i][buy][last] != -1)
            return dp[i][buy][last];
        int ans1 = 0;
        if(buy && !last)
            ans1 = solve(prices, i + 1, false, false, dp) - prices[i];
        if(!buy)
            ans1 = solve(prices, i + 1, true, true, dp) + prices[i];
        int ans2 = solve(prices, i + 1, buy, false, dp);
        return dp[i][buy][last] = max(ans1, ans2);
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(prices, 0, true, false, dp);
    }
};
