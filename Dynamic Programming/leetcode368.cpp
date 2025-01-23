#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 1;
        int lastIdx = 0;
        for(int i = 0; i < n; i++)
            hash[i] = i;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
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
        while(lastIdx != hash[lastIdx]) {
            res.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        res.push_back(nums[lastIdx]);
        return res;
    }
};
