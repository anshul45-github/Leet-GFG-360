// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool find(vector<int>& arr, int i, int target, vector<vector<int>>& dp) {
        if(target == 0)
            return true;
        if(i == arr.size() || target < 0)
            return false;
        if(dp[i][target] != -1)
            return dp[i][target];
        return dp[i][target] = find(arr, i + 1, target - arr[i], dp) || find(arr, i + 1, target, dp);
    }
  public:
    bool equalPartition(vector<int>& arr) {
        int target = accumulate(arr.begin(), arr.end(), 0);
        if(target & 1)
            return false;
        target = target >> 1;
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
        return find(arr, 0, target, dp);
    }
};