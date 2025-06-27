// https://www.geeksforgeeks.org/problems/minimal-cost/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& arr, int k, int i, vector<int>& dp) {
        if(i == arr.size() - 1)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for(int idx = i + 1; idx <= min(i + k, (int)arr.size() - 1); idx++)
            ans = min(ans, solve(arr, k, idx, dp) + abs(arr[idx] - arr[i]));
        return dp[i] = ans;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        vector<int> dp(arr.size() + 1, -1);
        return solve(arr, k, 0, dp);
    }
};