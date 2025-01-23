#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size(), {1, 1});
        int maxLen = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(dp[i].first < dp[j].first + 1)
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    else if(dp[i].first == dp[j].first + 1)
                        dp[i].second += dp[j].second;
                }
            }
            maxLen = max(maxLen, dp[i].first);
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(dp[i].first == maxLen)
                sum += dp[i].second;
        }
        return sum;
    }
};
