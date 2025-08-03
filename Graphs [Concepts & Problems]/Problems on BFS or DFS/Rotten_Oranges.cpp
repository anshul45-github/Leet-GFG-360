// https://leetcode.com/problems/rotting-oranges/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                grid[x][y] = 2;
                for(auto& direction : directions) {
                    int nx = x + direction[0];
                    int ny = y + direction[1];
                    if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[nx].size()) {
                        if(grid[nx][ny] == 1) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            if(!q.empty())
                cnt++;
        }
        return cnt;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) 
                    q.push({i, j});
            }
        }
        cnt = bfs(q, grid);
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) 
                    return -1;
            }
        }
        return cnt;
    }
};