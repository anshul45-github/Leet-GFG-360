// https://leetcode.com/problems/house-robber/
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if(i >= nums.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int include = solve(nums, i + 2, dp) + nums[i];
        int exclude = solve(nums, i + 1, dp);
        return dp[i] = max(include, exclude);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans = solve(nums, 0, dp);
        return ans;
    }
};
