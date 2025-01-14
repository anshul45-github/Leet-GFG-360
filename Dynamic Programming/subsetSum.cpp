#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>& arr, int i, int target, vector<vector<int>>& dp) {
        if(target == 0)
            return true;
        if(i == arr.size() || target < 0)
            return false;
        if(dp[i][target] != -1)
            return dp[i][target];
        bool include = solve(arr, i + 1, target, dp);
        bool exclude = solve(arr, i + 1, target - arr[i], dp);
        return dp[i][target] = include || exclude;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
        return solve(arr, 0, target, dp);
    }
};
