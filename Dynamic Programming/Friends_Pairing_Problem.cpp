// https://www.geeksforgeeks.org/problems/friends-pairing-problem5425/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n, int i, int pairsOpened, vector<vector<int>>& dp) {
        if(i == n) 
            return !pairsOpened;
        if(dp[i][pairsOpened] != -1)
            return dp[i][pairsOpened];
        int ans = solve(n, i + 1, pairsOpened, dp);
        ans += solve(n, i + 1, pairsOpened + 1, dp);
        if(pairsOpened)
            ans += solve(n, i + 1, pairsOpened - 1, dp) * pairsOpened;
        return dp[i][pairsOpened] = ans;
    }
  public:
    int countFriendsPairings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, 0, 0, dp);
    }
};
