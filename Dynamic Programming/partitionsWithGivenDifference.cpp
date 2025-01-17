#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& arr, int i, int sum, int totalSum, int d, vector<vector<int>>& dp) {
        if(i == arr.size()) {
            int sum2 = totalSum - sum;
            if(sum >= sum2 && sum - sum2 == d)
                return 1;
            return 0;
        }
        if(dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = solve(arr, i + 1, sum + arr[i], totalSum, d, dp) + solve(arr, i + 1, sum, totalSum, d, dp);
    }
  public:
    int countPartitions(vector<int>& arr, int d) {
        int sum = 0;
        for(int a : arr)
            sum += a;
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return solve(arr, 0, 0, sum, d, dp);
    }
};
