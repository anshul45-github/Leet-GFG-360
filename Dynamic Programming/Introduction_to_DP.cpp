// https://www.geeksforgeeks.org/problems/introduction-to-dp/1

#include<bits/stdc++.h>
using namespace std;

#define N 1000000007

class Solution {
    long long solve(int n, vector<long long>& dp) {
        if(n == 0 || n == 1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        dp[n] %= N;
        return dp[n];
    }
  public:
    long long int topDown(int n) {
        vector<long long> dp(n + 1, -1);
        // cout<<"topdown";
        return solve(n, dp);
    }

    long long int bottomUp(int n) {
        vector<long long> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % N;
        return dp[n];
    }
};