#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findSubsequences(vector<int>& arr, int target, int i, vector<vector<int>>& dp) {
        if(i == arr.size() || target < 0)
            return target == 0 ? 1 : 0;
        if(dp[target][i] != -1)
            return dp[target][i];
        return dp[target][i] = findSubsequences(arr, target, i + 1, dp) + findSubsequences(arr, target - arr[i], i + 1, dp);
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(target + 1, vector<int>(arr.size(), -1));
        return findSubsequences(arr, target, 0, dp);
    }
};
