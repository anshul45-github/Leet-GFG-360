// https://leetcode.com/problems/maximum-length-of-pair-chain/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& pairs, int i, int prev, vector<vector<int>>& dp) {
        if(i == pairs.size())
            return 0;
        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int ans = solve(pairs, i + 1, prev, dp);
        if(prev == -1 || pairs[prev][1] < pairs[i][0])
            ans = max(ans, solve(pairs, i + 1, i, dp) + 1);
        return dp[i][prev + 1] = ans;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(pairs.size() + 1, vector<int>(pairs.size() + 2, -1));
        return solve(pairs, 0, -1, dp);
    }
};