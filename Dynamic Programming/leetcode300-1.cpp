#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums, int i, int next, vector<vector<int>>& dp) {
        if(i == -1)
            return 0;
        if(dp[i][next] != -1)
            return dp[i][next];
        int ans1 = 0;
        if(nums[i] < nums[next])
            ans1 = solve(nums, i - 1, i, dp) + 1;
        int ans2 = solve(nums, i - 1, next, dp);
        return dp[i][next] = max(ans1, ans2);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        nums.insert(nums.end(), INT_MAX);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, nums.size() - 2, nums.size() - 1, dp);        
    }
};
