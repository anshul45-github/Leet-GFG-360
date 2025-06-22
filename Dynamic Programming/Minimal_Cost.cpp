// https://www.geeksforgeeks.org/problems/minimal-cost/1
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& height, int n, int k, vector<int>& dp) {
        if(n < 0)
            return INT_MAX;
        if(n == 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        int ans = INT_MAX;
        for(int i = 1; i <= k; i++) {
            int a = solve(height, n - i, k, dp);
            if(a != INT_MAX)
                ans = min(ans, solve(height, n - i, k, dp) + abs(height[n] - height[n - i]));
        }
        return dp[n] = ans;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        vector<int> dp(arr.size(), -1);
        int ans = solve(arr, arr.size() - 1, k, dp);
        
        return ans;
    }
};
