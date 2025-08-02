// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include<bits/stdc++.h>
using namespace std;

class Solution {    
    int solve(vector<int>& arr, int i, int target, vector<vector<int>>& dp) {
        if(target < 0 || i == arr.size())
            return target == 0;
        if(dp[i][target] != -1)
            return dp[i][target];
        return dp[i][target] = solve(arr, i + 1, target - arr[i], dp) + solve(arr, i + 1, target, dp);
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, -1));
        return solve(arr, 0, target, dp);
    }
};