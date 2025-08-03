#include<bits/stdc++.h>
using namespace std;

class Solution {
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if(grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        for(int k = 0; k < 4; k++) {
            int nx = i + x[k];
            int ny = j + y[k];
            dfs(grid, nx, ny);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    num++;
                    dfs(grid, i, j);
                }
            }
        }
        return num;
    }
};