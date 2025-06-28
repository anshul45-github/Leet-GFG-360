// https://leetcode.com/problems/partition-array-for-maximum-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& arr, int k, int idx, vector<int>& dp) {
        if(idx == arr.size())
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int maxi = 0;
        int ans = 0;
        for(int i = idx; i < min(idx + k, (int)arr.size()); i++) {
            maxi = max(maxi, arr[i]);
            ans = max(ans, solve(arr, k, i + 1, dp) + maxi * (i - idx + 1));
        }
        return dp[idx] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1, -1);
        return solve(arr, k, 0, dp);
    }
};