// https://leetcode.com/problems/house-robber/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if(i >= nums.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int robIt = solve(nums, i + 2, dp) + nums[i];
        int leaveIt = solve(nums, i + 1, dp);
        return dp[i] = max(robIt, leaveIt);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(nums, 0, dp);
        // return max(solve(nums, 0), solve(nums, 1));
    }
};