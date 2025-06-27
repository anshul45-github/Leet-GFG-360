// https://www.geeksforgeeks.org/problems/geek-jump/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long solve(vector<int>& height, int i, vector<long long>& dp) {
        if(i == height.size())
            return 1e9;
        if(i == height.size() - 1) 
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = min(solve(height, i + 1, dp) + abs(1LL * height[i + 1] - 1LL * height[i]), solve(height, i + 2, dp) + abs(1LL * height[i + 2] - 1LL * height[i]));
    }
  public:
    int minCost(vector<int>& height) {
        vector<long long> dp(height.size() + 1, -1);
        return solve(height, 0, dp);
    }
};