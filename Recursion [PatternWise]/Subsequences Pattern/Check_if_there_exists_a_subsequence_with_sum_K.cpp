// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>& arr, int sum, int i, vector<vector<int>>& dp) {
        if(sum == 0)
            return true;    
        if(sum < 0 || i == arr.size())
            return false;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        bool include = solve(arr, sum - arr[i], i + 1, dp);
        bool exclude = solve(arr, sum, i + 1, dp);
        return dp[i][sum] = include || exclude;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }
};