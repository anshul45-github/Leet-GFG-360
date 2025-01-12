#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& arr, int idx, int prev) {
        if(idx == arr.size())
            return 0;
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            if(i == prev)
                continue;
            ans = max(ans, solve(arr, idx + 1, i) + arr[idx][i]);
        }
        return ans;
    }
    int solveMem(vector<vector<int>>& arr, int idx, int prev, vector<vector<int>>& dp) {
        if(idx == arr.size())
            return 0;
        if(dp[idx][prev] != -1)
            return dp[idx][prev];
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            if(i == prev - 1)
                continue;
            ans = max(ans, solveMem(arr, idx + 1, i + 1, dp) + arr[idx][i]);
        }
        dp[idx][prev] = ans;
        return ans;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(4, -1));
        return solveMem(arr, 0, 0, dp);
    }
};
