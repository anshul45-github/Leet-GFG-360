// https://www.geeksforgeeks.org/problems/nth-catalan-number0817/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int open, int closed, vector<vector<int>>& dp) {
        if(closed < open)
            return 0;
        if(open == 0)
            return 1;
        if(dp[open][closed] != -1)
            return dp[open][closed];
        int openBracket = solve(open - 1, closed, dp);
        int closeBracket = solve(open, closed - 1, dp);
        return dp[open][closed] = openBracket + closeBracket;
    }
  public:
    int findCatalan(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, n, dp);
    }
};