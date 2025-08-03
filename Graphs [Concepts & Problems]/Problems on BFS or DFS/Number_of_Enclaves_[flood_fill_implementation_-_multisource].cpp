// https://leetcode.com/problems/number-of-enclaves/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1)
            return;
        grid[i][j] = 0;
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i, j - 1, n, m);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1)
                dfs(grid, i, 0, n, m);
            if(grid[i][m - 1] == 1)
                dfs(grid, i, m - 1, n, m);
        }
        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 1)
                dfs(grid, 0, i, n, m);
            if(grid[n - 1][i] == 1)
                dfs(grid, n - 1, i, n, m);
        }
        int cnt = 0;
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(grid[i][j] == 1) 
                    cnt++;
            }
        }
        return cnt;
    }
};
