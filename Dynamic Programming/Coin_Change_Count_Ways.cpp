// https://www.geeksforgeeks.org/problems/coin-change2448/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& coins, int sum, int i, vector<vector<int>>& dp) {
        if(sum == 0)
            return 1;
        if(sum < 0 || i == coins.size())
            return 0;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        int include = solve(coins, sum - coins[i], i, dp);
        int exclude = solve(coins, sum, i + 1, dp);
        return dp[i][sum] = include + exclude;
    }
  public:
    int count(vector<int>& coins, int sum) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(sum + 1, -1));
        return solve(coins, sum, 0, dp);
    }
};