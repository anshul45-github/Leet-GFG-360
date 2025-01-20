#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveTab(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        for(int i = nums.size() - 1; i >= 1; i--) {
            for(int j = i - 1; j >= 0; j--) {
                int ans1 = 0;
                if(nums[i] > nums[j])
                    ans1 = dp[i + 1][i] + 1;
                int ans2 = dp[i + 1][j];
                dp[i][j] = max(ans1, ans2);
            }
        }
        return dp[1][0];
    }
  public:
    int lis(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        return solveTab(nums);
    }
};
