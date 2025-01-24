#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if(j == i + 1)
            return 0;
        if(dp[i][j] != -1)  
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            ans = min(ans, (arr[i] * arr[k] * arr[j]) + solve(arr, i, k, dp) + solve(arr, k, j, dp));
        }
        return dp[i][j] = ans;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        vector<vector<int>> dp(arr.size() - 1, vector<int>(arr.size(), -1));
        return solve(arr, 0, arr.size() - 1, dp);
    }
};
