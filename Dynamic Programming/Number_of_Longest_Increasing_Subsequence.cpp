// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        vector<int> dp(arr.size(), 1);
        vector<int> noOfLis(arr.size(), 1);
        int lenlis = 1;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j]) { 
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        noOfLis[i] = noOfLis[j];
                    }
                    else if(dp[i] == dp[j] + 1)
                        noOfLis[i] += noOfLis[j];
                }
            }
            lenlis = max(lenlis, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i < dp.size(); i++) {
            if(dp[i] == lenlis)
                ans += noOfLis[i];
        }
        return ans;
    }
};