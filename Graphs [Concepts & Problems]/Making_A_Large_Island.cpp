// https://leetcode.com/problems/making-a-large-island/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& parent, int par, vector<vector<bool>>& vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || vis[i][j] || grid[i][j] == 0)
            return 0;
        vis[i][j] = true;
        parent[i][j] = par;
        int ans = 1;
        for(auto& direction : directions) 
            ans += dfs(grid, i + direction[0], j + direction[1], parent, par, vis);
        return ans;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> parent(grid.size(), vector<int>(grid.size()));
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid.size(), false));
        unordered_map<int, int> area;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    int hash = i * grid.size() + j;
                    int a = dfs(grid, i, j, parent, hash, vis);
                    area[hash] = a;
                    ans = max(ans, a);
                }
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> s;
                    if(j + 1 < grid.size() && grid[i][j + 1] == 1)
                        s.insert(parent[i][j + 1]);
                    if(i + 1 < grid.size() && grid[i + 1][j] == 1)
                        s.insert(parent[i + 1][j]);
                    if(i - 1 >= 0 && grid[i - 1][j] == 1)
                        s.insert(parent[i - 1][j]);
                    if(j - 1 >= 0 && grid[i][j - 1] == 1)
                        s.insert(parent[i][j - 1]);
                    int tot = 0;
                    for(int x : s) 
                        tot += area[x];
                    ans = max(ans, tot + 1);
                }
            }
        }
        return ans;
    }
};