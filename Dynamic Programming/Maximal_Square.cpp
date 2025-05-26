// https://leetcode.com/problems/maximal-square/
// Medium

// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// A square is a submatrix with all four sides of equal length.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],
//                 ["1","0","1","1","1"],
//                 ["1","1","1","1","1"],
//                 ["1","0","0","1","0"]]
// Output: 4
// Explanation: The largest square has a side length of 2, and its area is 2 * 2 = 4.

// Example 2:
// Input: matrix = [["0","1"],
//                 ["1","0"]]
// Output: 1
// Explanation: The largest square has a side length of 1, and its area is 1 * 1 = 1.

// Example 3:
// Input: matrix = [["0"]]
// Output: 0
// Explanation: There are no 1's in the matrix, so the largest square has a side length of 0, and its area is 0 * 0 = 0.

#include<vector>
using namespace std;

class Solution {
    int solve(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if(i == matrix.size() || j == matrix[0].size() || matrix[i][j] == '0')
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int right = solve(matrix, i, j + 1, dp);
        int down = solve(matrix, i + 1, j, dp);
        int diagonal = solve(matrix, i + 1, j + 1, dp);
        return dp[i][j] = min(right, min(down, diagonal)) + 1;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int maxi = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(dp[i][j] == -1)
                    solve(matrix, i, j, dp);
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi * maxi;
    }
};