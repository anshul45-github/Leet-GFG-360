// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& arr, int sum, int i, vector<vector<int>>& dp) {
        if(sum < 0 || i == arr.size())
            return sum == 0;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        // int ans = 0;
        // if(sum == 0)
        //     ans++;
        int include = solve(arr, sum - arr[i], i + 1, dp);
        int exclude = solve(arr, sum, i + 1, dp);
        return dp[i][sum] = include + exclude;
    }
  public:
    int perfectSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }
};