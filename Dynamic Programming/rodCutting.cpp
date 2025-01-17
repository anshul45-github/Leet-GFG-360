#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices, int length, vector<int>& dp) {
        if(length == 0)
            return 0;
        if(length < 0)
            return INT_MAX;
        if(dp[length] != -1)
            return dp[length];
        int profit = 0;
        for(int i = 1; i <= length; i++)
            profit = max(profit, solve(prices, length - i, dp) + prices[i - 1]);
        return dp[length] = profit;
    }
  public:
    int cutRod(vector<int> &price) {
        vector<int> dp(price.size() + 1, -1);
        return solve(price, price.size(), dp);
    }
};
