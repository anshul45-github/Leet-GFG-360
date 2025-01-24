#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveTab(vector<int>& arr) {
        vector<vector<int>> dp(arr.size() - 1, vector<int>(arr.size(), 0));
        for(int i = arr.size() - 2; i >= 0; i--) {
            for(int j = i + 2; j < arr.size(); j++) {
                int ans = INT_MAX;
                for(int k = i + 1; k < j; k++)
                    ans = min(ans, (arr[i] * arr[k] * arr[j]) + dp[i][k] + dp[k][j]);
                dp[i][j] = ans;
            }
        }
        return dp[0][arr.size() - 1];
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        return solveTab(arr);
    }
};
