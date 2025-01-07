// TC : O(N), SC : O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& height, int n, vector<int>& dp) {
        if(n == 1)
            return abs(height[1] - height[0]);
        if(n == 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        int ans = min(solve(height, n - 1, dp) + abs(height[n] - height[n - 1]), solve(height, n - 2, dp) + abs(height[n] - height[n - 2]));
        return dp[n] = ans;
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n, -1);
        int ans = solve(height, n - 1, dp);
        
        return ans;
    }
};
