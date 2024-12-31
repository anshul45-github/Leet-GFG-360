#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        int ans = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int a = solve(coins, amount - coins[i]) + 1;
            if(a != 0)
                ans = min(ans, a);
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
    int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        if(dp[amount] != -1)
            return dp[amount];
        int ans = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int a = solveMem(coins, amount - coins[i], dp) + 1;
            if(a != 0)
                ans = min(ans, a);
        }
        dp[amount] = (ans == INT_MAX) ? -1 : ans;
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
    int solveTab(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solve(coins, amount);

        // vector<int> dp(amount + 1, -1);
        // int ans = solveMem(coins, amount, dp);

        int ans = solveTab(coins, amount);

        return ans;
    }
};
