#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if(i + 1 >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        int cost = cuts[j] - cuts[i];
        for(int k = i + 1; k < j; k++)
            ans = min(ans, cost + solve(cuts, i, k, dp) + solve(cuts, k, j, dp));
        return dp[i][j] = ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size() - 1, vector<int>(cuts.size(), -1));
        return solve(cuts, 0, cuts.size() - 1, dp);
    }
};
