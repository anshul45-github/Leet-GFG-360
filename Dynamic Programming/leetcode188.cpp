#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices, int i, int opNo, vector<vector<int>>& dp, int k) {
        if(opNo == 2 * k || i == prices.size())
            return 0;
        if(dp[i][opNo] != -1)
            return dp[i][opNo];
        int ans1 = 0;
        if(opNo % 2 == 0)
            ans1 = solve(prices, i + 1, opNo + 1, dp, k) - prices[i];
        else
            ans1 = solve(prices, i + 1, opNo + 1, dp, k) + prices[i];
        int ans2 = solve(prices, i + 1, opNo, dp, k);
        return dp[i][opNo] = max(ans1, ans2);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, - 1));
        return solve(prices, 0, 0, dp, k);
    }
};
