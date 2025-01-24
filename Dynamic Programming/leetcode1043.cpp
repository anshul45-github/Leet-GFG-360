#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& arr, int idx, int k, vector<int>& dp) {
        if(idx >= arr.size())
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int maxi = arr[idx];
        int ans = 0;
        for(int i = idx; i < idx + k && i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
            ans = max(ans, ((i - idx + 1) * maxi) + solve(arr, i + 1, k, dp));
        }
        return dp[idx] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return solve(arr, 0, k, dp);
    }
};
