#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& val, vector<int>& wt, int capacity, vector<int>& dp) {
        if(capacity == 0)
            return 0;
        if(capacity < 0)
            return INT_MIN;
        if(dp[capacity] != -1)
            return dp[capacity];
        int profit = 0;
        for(int i = 0; i < wt.size(); i++)
            profit = max(solve(val, wt, capacity - wt[i], dp) + val[i], profit);
        return dp[capacity] = profit;
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<int> dp(capacity + 1, -1);
        return solve(val, wt, capacity, dp);
    }
};
