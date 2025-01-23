// TC : O(N^2), SC : O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i = 0; i < n; i++)
            hash[i] = i;
        int maxi = 1;
        int lastIdx = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(maxi < dp[i]) {
                maxi = dp[i];
                lastIdx = i;
            }
        }
        vector<int> res;
        while(hash[lastIdx] != lastIdx) {
            res.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        res.push_back(nums[lastIdx]);
        reverse(res.begin(), res.end());
        return res;
    }
};
