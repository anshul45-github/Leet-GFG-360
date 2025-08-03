#include<bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, int color, int originalColor) {
        while(!q.empty()) {
            pair<int, int> p = q.front();
            int i = p.first, j = p.second;
            q.pop();
            if(i + 1 < grid.size() && grid[i + 1][j] == originalColor) {
                grid[i + 1][j] = color;
                q.push({i + 1, j});
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == originalColor) {
                grid[i][j + 1] = color;
                q.push({i, j + 1});
            }
            if(i >= 1 && grid[i - 1][j] == originalColor) {
                grid[i - 1][j] = color;
                q.push({i - 1, j});
            }
            if(j >= 1 && grid[i][j - 1] == originalColor) {
                grid[i][j - 1] = color;
                q.push({i, j - 1});
            }
        }
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int originalColor = grid[sr][sc];
        if(originalColor == color)
            return grid;
        grid[sr][sc] = color;
        q.push({sr, sc});
        bfs(q, grid, color, originalColor);
        return grid;
    }
};
