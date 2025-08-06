// https://leetcode.com/problems/making-a-large-island/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, int parX, int parY, vector<vector<vector<int>>>& parent) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0 || vis[i][j])
            return 0;
        vis[i][j] = true;
        parent[i][j] = {parX, parY};
        int tot = 1;
        for(auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            tot += dfs(grid, ni, nj, vis, parX, parY, parent);
        }
        return tot;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> area;
        vector<vector<vector<int>>> parent(grid.size(), vector<vector<int>>(grid[0].size()));
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    int a = dfs(grid, i, j, vis, i, j, parent);
                    area[i * grid[i].size() + j] = a;
                    maxArea = max(maxArea, a);
                }
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> parents;
                    for(auto& d : dirs) {
                        int ni = i + d[0], nj = j + d[1];
                        if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[ni].size() && grid[ni][nj] == 1) {
                            auto p = parent[ni][nj];
                            int conversion = p[0] * grid[0].size() + p[1];
                            parents.insert(conversion);
                        }
                    }
                    int a = 1;
                    for(int p : parents)
                        a += area[p];
                    maxArea = max(maxArea, a);
                }
            }
        }
        return maxArea;
    }
};