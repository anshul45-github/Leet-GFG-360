// https://leetcode.com/problems/flood-fill/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, int color, int originalColor) {
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                grid[x][y] = color;
                for(auto& direction : directions) {
                    int nx = x + direction[0];
                    int ny = y + direction[1];
                    if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[nx].size()) {
                        if(grid[nx][ny] == originalColor) {
                            grid[nx][ny] = color;
                            q.push({nx, ny});
                        }
                    }
                }
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