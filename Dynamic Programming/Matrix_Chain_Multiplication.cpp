// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if(j <= i + 1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = i + 1; k <= j - 1; k++)
            ans = min(ans, solve(arr, i, k, dp) + solve(arr, k, j, dp) + arr[i] * arr[j] * arr[k]);
        return dp[i][j] = ans;
    }
    int solveTab(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        for(int i = arr.size() - 3; i >= 0; i--) {
            for(int j = i + 2; j < arr.size(); j++) {
                int ans = INT_MAX;
                for(int k = i + 1; k <= j - 1; k++)
                    ans = min(ans, dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k]);
                dp[i][j] = ans;
            }
        }
        return dp[0][arr.size() - 1];
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        // return solve(arr, 0, arr.size() - 1, dp);
        return solveTab(arr);
    }
};