// https://www.geeksforgeeks.org/problems/geeks-training/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& arr, int i, int last, vector<vector<int>>& dp) {
        if(i == arr.size())
            return 0;
        if(dp[i][last] != -1)
            return dp[i][last];
        int ans = 0;
        for(int activity = 0; activity < 3; activity++) {
            if(activity == last)
                continue;
            ans = max(ans, solve(arr, i + 1, activity, dp) + arr[i][activity]);
        }
        // cout << ans << " ";
        return dp[i][last] = ans;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // int last = 3;
        vector<vector<int>> dp(arr.size() + 1, vector<int>(4, -1));
        return solve(arr, 0, 3, dp);
    }
};