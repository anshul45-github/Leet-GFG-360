// https://leetcode.com/problems/burst-balloons/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        for(int k = i + 1; k < j; k++)
            ans = max(ans, solve(nums, i, k, dp) + solve(nums, k, j, dp) + nums[i] * nums[j] * nums[k]);
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, 0, nums.size() - 1, dp);
    }
};