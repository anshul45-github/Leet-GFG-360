#include<bits/stdc++.h>
using namespace std;

class Solution {
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>>& grid, int i, int j, int& cnt) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        cnt++;
        for(int k = 0; k < 4; k++) {
            int nx = i + x[k];
            int ny = j + y[k];
            dfs(grid, nx, ny, cnt);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                int cnt = 0;
                dfs(grid, i, j, cnt);
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};