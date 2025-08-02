// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& a, int m, vector<int>& dp) {
        if(m == 0)
            return 0;
        if(m < 0)
            return INT_MIN;
        if(dp[m] != -1)
            return dp[m];
        int ans = INT_MIN;
        for(int i = 0; i < a.size(); i++) {
            ans = max(ans, a[i] + solve(a, m - i - 1, dp));
        }
        return dp[m] = ans;
    }
  public:
    int cutRod(vector<int> &price) {
        vector<int> dp(price.size() + 1, -1);
        return solve(price, price.size(), dp);
    }
};
