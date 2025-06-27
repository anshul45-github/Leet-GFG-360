// https://leetcode.com/problems/partition-equal-subset-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>& nums, int n, int target, int i) {
        if(target == 0)
            return true;
        if(i == n || target < 0)
            return false;
        int include = solve(nums, n, target - nums[i], i + 1);
        int exclude = solve(nums, n, target, i + 1);
        return include || exclude;
    }
    bool solveMem(vector<int>& nums, int n, int target, int i, vector<vector<int>>& dp) {
        if(target == 0)
            return true;
        if(i == n || target < 0)
            return false;
        if(dp[target][i] != -1)
            return dp[target][i];
        int include = solveMem(nums, n, target - nums[i], i + 1, dp);
        int exclude = solveMem(nums, n, target, i + 1, dp);
        dp[target][i] = include || exclude ? 1 : 0;
        return dp[target][i];
    }
    bool solveTab(vector<int>& nums, int sum) {
        vector<vector<int>> dp(sum + 1, vector<int>(nums.size(), -1));
        for(int i = 0; i < nums.size(); i++)
            dp[0][i] = 1;
        for(int i = 1; i <= sum; i++) {
            for(int j = nums.size() - 1; j >= 0; j--) {
                int include = 0;
                if(i - nums[j] >= 0)
                    include = j + 1 < nums.size() ? dp[i - nums[j]][j + 1] : 0;
                int exclude = j + 1 < nums.size() ? dp[i][j + 1] : 0;
                dp[i][j] = include || exclude;
            }
        }
        return dp[sum][0];
    }
    bool spaceOptimization(vector<int>& nums, int sum) {
        vector<int> next(sum + 1, 0);
        next[0] = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            vector<int> curr(sum + 1, 0);
            curr[0] = 1;
            for(int j = 1; j <= sum; j++) {
                int include = 0;
                if(j - nums[i] >= 0)
                    include = i + 1 < nums.size() ? next[j - nums[i]] : 0;
                int exclude = i + 1 < nums.size() ? next[j] : 0;
                curr[j] = include || exclude;
            }
            next = curr;
        }
        return next[sum];
    }
    bool spaceOptimization2(vector<int>& nums, int sum) {
        vector<int> next(sum + 1, 0);
        next[0] = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            // vector<int> curr(sum + 1, 0);
            // curr[0] = 1;
            for(int j = sum; j >= 1; j--) {
                int include = 0;
                if(j - nums[i] >= 0)
                    include = i + 1 < nums.size() ? next[j - nums[i]] : 0;
                int exclude = i + 1 < nums.size() ? next[j] : 0;
                next[j] = include || exclude;
            }
            // next = curr;
        }
        return next[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % 2)
            return false;

        // bool ans = solve(nums, nums.size(), sum / 2, 0);

        // vector<vector<int>> dp((sum / 2) + 1, vector<int>(nums.size(), -1));
        // bool ans = solveMem(nums, nums.size(), sum / 2, 0, dp);

        // bool ans = solveTab(nums, sum / 2);

        // bool ans = spaceOptimization(nums, sum / 2);

        bool ans = spaceOptimization2(nums, sum / 2);

        return ans;
    }
};