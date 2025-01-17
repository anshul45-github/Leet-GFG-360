#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if(amount == 0)
            return 1;
        if(i == coins.size() || amount < 0)
            return 0;
        if(dp[i][amount] != -1)
            return dp[i][amount];
        int ans1 = solve(coins, amount - coins[i], i, dp);
        int ans2 = solve(coins, amount, i + 1, dp);
        return dp[i][amount] = ans1 + ans2;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(coins, amount, 0, dp);
    }
};
