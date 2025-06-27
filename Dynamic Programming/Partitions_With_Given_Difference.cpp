// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& arr, int sum, int d, int i, int currSum, vector<vector<int>>& dp) {
        if(i == arr.size()) {
            int sum2 = sum - currSum;
            if(currSum >= sum2 && currSum - sum2 == d)
                return 1;
            return 0;
        }
        if(dp[i][currSum] != -1)
            return dp[i][currSum];
        int include = solve(arr, sum, d, i + 1, currSum + arr[i], dp);
        int exclude = solve(arr, sum, d, i + 1, currSum, dp);
        return dp[i][currSum] = include + exclude;
    }
  public:
    int countPartitions(vector<int>& arr, int d) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, -1));
        return solve(arr, sum, d, 0, 0, dp);
    }
};