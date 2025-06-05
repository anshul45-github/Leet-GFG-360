// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// Medium

// Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

// In 0/1 knapsack, a particular item can either be included in the knapsack or not.

// The problem can be solved using dynamic programming.

#include <vector>
using namespace std;

class Solution {
    int solve(vector<int>& val, vector<int>& wt, int W, int i, vector<vector<int>>& dp) {
        if(i == val.size())
            return 0;
        if(dp[i][W] != -1)
            return dp[i][W];
        int ans = solve(val, wt, W, i + 1, dp);
        if(wt[i] <= W)
            ans = max(ans, solve(val, wt, W - wt[i], i + 1, dp) + val[i]);
        return dp[i][W] = ans;
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(), vector<int>(W + 1, -1));
        return solve(val, wt, W, 0, dp);
    }
};