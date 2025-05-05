// https://leetcode.com/problems/domino-and-tromino-tiling/
// 790. Domino and Tromino Tiling
// Medium

#include<vector>
using namespace std;

#define N 1000000007

class Solution {
    int solve(int i, int n, bool gap, vector<vector<int>>& dp) {
        if(i == n)
            return !gap;
        if(i > n)
            return 0;
        if(dp[i][gap] != -1)
            return dp[i][gap];
        if(!gap)
            return dp[i][gap] = (1LL * solve(i + 1, n, false, dp) + 1LL * solve(i + 2, n, false, dp) + 2LL * solve(i + 2, n, true, dp)) % N;
        return dp[i][gap] = (1LL * solve(i + 1, n, false, dp) + 1LL * solve(i + 1, n, true, dp)) % N;

    }
public:
    int numTilings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        int ans = solve(0, n, false, dp);
        return ans;
    }
};