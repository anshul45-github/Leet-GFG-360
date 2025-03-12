#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& dp, int i) {
        if(i == 0 || i == 1)
            return i;
        if(dp[i] != -1)
            return dp[i];
        if(i % 2 == 0)
            return dp[i] = solve(dp, i >> 1);
        return dp[i] = solve(dp, i >> 1) + 1;
    }
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, -1);
        for(int i = 0; i <= n; i++)
            dp[i] = solve(dp, i);
        return dp;
    }
};
