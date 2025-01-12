#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveTab(vector<vector<int>>& grid) {
        vector<int> next(grid[0].size() + 1, 1e9);
        vector<int> curr(grid[0].size() + 1, 1e9);
        curr[grid[0].size() - 1] = grid[grid.size() - 1][grid[0].size() - 1];
        for(int i = grid.size() - 1; i >= 0; i--) {
            for(int j = grid[0].size() - 1; j >= 0; j--) {
                if(i == grid.size() - 1 && j == grid[0].size() - 1)
                    continue;
                curr[j] = min(next[j], curr[j + 1]) + grid[i][j];
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return solveTab(grid);
    }
};
