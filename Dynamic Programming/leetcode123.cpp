#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices, int i, int opNo, vector<vector<int>>& dp) {
        if(opNo == 4 || i == prices.size())
            return 0;
        if(dp[i][opNo] != -1)
            return dp[i][opNo];
        int ans1 = 0;
        if(opNo % 2 == 0)
            ans1 = solve(prices, i + 1, opNo + 1, dp) - prices[i];
        else
            ans1 = solve(prices, i + 1, opNo + 1, dp) + prices[i];
        int ans2 = solve(prices, i + 1, opNo, dp);
        return dp[i][opNo] = max(ans1, ans2);
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, - 1));
        return solve(prices, 0, 0, dp);
    }
};
