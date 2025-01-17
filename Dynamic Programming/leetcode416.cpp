#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        if(target == 0)
            return true;
        if(i == nums.size() || target < 0)
            return false;
        if(dp[i][target] != -1)
            return dp[i][target];
        bool include = solve(nums, target - nums[i], i + 1, dp);
        bool exclude = solve(nums, target, i + 1, dp);
        return dp[i][target] = include || exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % 2 == 0) {
            sum = sum / 2;
            vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
            bool ans = solve(nums, sum, 0, dp);
            return ans;
        }
        return false;
    }
};
