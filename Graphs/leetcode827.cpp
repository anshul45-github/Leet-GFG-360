#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x, int y, int par, vector<vector<int>>& parent, int& a) {
        if(vis[x][y] || grid[x][y] != 1)
            return;
        vis[x][y] = true;
        parent[x][y] = par;
        a++;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto direction : directions) {
            int nx = x + direction[0];
            int ny = y + direction[1];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size())
                dfs(grid, vis, x + direction[0], y + direction[1], par, parent, a);
        }
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
                    int a = 0;
                    dfs(grid, vis, i, j, (i * grid.size()) + j, parent, a);
                    area[(i * grid.size()) + j] = a;
                    ans = max(ans, a);
                }
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> s;
                    if(i + 1 < grid.size() && grid[i + 1][j] == 1)
                        s.insert(parent[i + 1][j]);
                    if(i - 1 >= 0 && grid[i - 1][j] == 1)
                        s.insert(parent[i - 1][j]);
                    if(j - 1 >= 0 && grid[i][j - 1] == 1)
                        s.insert(parent[i][j - 1]);
                    if(j + 1 < grid.size() && grid[i][j + 1] == 1)
                        s.insert(parent[i][j + 1]);
                    int tot = 0;
                    for(auto a : s) {
                        if(area.count(a))
                            tot += area[a];
                    }
                    ans = max(ans, tot + 1);
                }
            }
        }
        return ans;
    }
};
