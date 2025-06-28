// https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Recursive approach - TLE
    int solve(vector<int>& nums, int i, int prev) {
        if(i == nums.size())
            return 0;
        int include = INT_MIN;
        if(prev == -1 || nums[i] > nums[prev])
            include = solve(nums, i + 1, i) + 1;
        int exclude = solve(nums, i + 1, prev);
        return max(include, exclude);
    }

    // Memoization approach
    int solveMem(vector<int>& nums, int i, int prev, vector<vector<int>>& dp) {
        if(i == nums.size())
            return 0;
        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int include = INT_MIN;
        if(prev == -1 || nums[i] > nums[prev])
            include = solveMem(nums, i + 1, i, dp) + 1;
        int exclude = solveMem(nums, i + 1, prev, dp);
        dp[i][prev + 1] = max(include, exclude);
        return dp[i][prev + 1];
    }

    // Tabulation approach
    int solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i - 1; j >= -1; j--) {
                int include = INT_MIN;
                if(j == -1 || nums[i] > nums[j])
                    include = dp[i + 1][i + 1] + 1;
                int exclude = dp[i + 1][j + 1];
                dp[i][j + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    // Space Optimization approach
    int spaceOptimization(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0);
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            vector<int> curr(n + 1);
            for(int j = i - 1; j >= -1; j--) {
                int include = INT_MIN;
                if(j == -1 || nums[i] > nums[j])
                    include = next[i + 1] + 1;
                int exclude = next[j + 1];
                curr[j + 1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

    // Binary Search approach (For intuition - https://www.youtube.com/watch?v=on2hvxBXJH4)
    int binarySearch(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > v.back())
                v.push_back(nums[i]);
            else {
                int index = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[index] = nums[i];
            }
        }
        return v.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        // int ans = solve(nums, 0, -1);

        // vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        // int ans = solveMem(nums, 0, -1, dp);

        // int ans = solveTab(nums);.

        // int ans = spaceOptimization(nums);

        int ans = binarySearch(nums);

        return ans;
    }
};

// 1D DP Approach
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> dp(arr.size(), 1);
        int lenlis = 1;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j] && dp[j] + 1 > dp[i]) 
                    dp[i] = dp[j] + 1;
            }
            if(dp[i] > lenlis) 
                lenlis = dp[i];
        }
        return lenlis;
    }
};