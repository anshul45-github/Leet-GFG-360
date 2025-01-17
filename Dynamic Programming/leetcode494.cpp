#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums, int i, int target, unordered_map<int, int> dp[]) {
        if(i == nums.size())
            return target == 0;
        if(dp[i].count(target))
            return dp[i][target];
        return dp[i][target] = solve(nums, i + 1, target + nums[i], dp) + solve(nums, i + 1, target - nums[i], dp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n : nums)
            sum += n;
        unordered_map<int, int> dp[nums.size()];
        return solve(nums, 0, target, dp);
    }
};
