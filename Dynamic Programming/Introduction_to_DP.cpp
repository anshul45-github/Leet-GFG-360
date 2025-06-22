// https://www.geeksforgeeks.org/problems/introduction-to-dp/1
// Medium

#include<bits/stdc++.h>
using namespace std;

#define N 1000000007

class Solution {
    long long int solveTopDown(int n, vector<long long int>& dp) {
        if(dp[n] != -1)
            return dp[n];
        dp[n] = (solveTopDown(n - 1, dp) + solveTopDown(n - 2, dp)) % N;
        return dp[n];
    }
  public:
    long long int topDown(int n) {
        vector<long long int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        return solveTopDown(n, dp);
    }
    long long int bottomUp(int n) {
        vector<long long int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % N;
        }
        return dp[n];
    }
};
