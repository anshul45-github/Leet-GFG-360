#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int solve(vector<vector<int>>& matrix, int i, int j, int curr, vector<vector<int>>& dp) {
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 1;
        for(auto direction : directions) {
            int x = i + direction[0];
            int y = j + direction[1];
            if(x < matrix.size() && y < matrix[0].size() && x >= 0 && y >= 0 && matrix[x][y] > matrix[i][j])
                ans = max(ans, solve(matrix, x, y, matrix[x][y], dp) + 1);
        }
        return dp[i][j] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 1;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, solve(matrix, i, j, matrix[i][j], dp));
            }
        }
        // TANUSHKA IS SUCH A CUTIEEEEEE
        return ans;
    }
};
