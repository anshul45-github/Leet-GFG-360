#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveTab(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix.size() + 1, 0));
        for(int i = matrix.size() - 1; i >= 0; i--) {
            for(int j = matrix.size() - 1; j >= 0; j--) {
                int ans = INT_MAX;
                for(int k = j - 1; k <= j + 1; k++) {
                    int val = (k < 0 || k == matrix.size()) ? 1e9 : dp[i + 1][k];
                    ans = min(ans, val + matrix[i][j]);
                }
                dp[i][j] = ans;
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < matrix.size(); i++)
            ans = min(ans, dp[0][i]);
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return solveTab(matrix);
    }
};
