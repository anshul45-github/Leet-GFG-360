#include<bits/stdc++.h>
using namespace std;

class Solution {
    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        int cnt = 0;
        while(!q.empty()) {
            pair<int, int> p = q.front();
            int i = p.first, j = p.second;
            q.pop();
            if(i == -1) {
                if(q.empty())
                    break;
                cnt++;
                q.push({-1, -1});
                continue;
            }
            if(i + 1 < grid.size() && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            }
            if(i >= 1 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            }
            if(j >= 1 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            }
        }
        return cnt;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        q.push({-1, -1});
        cnt = bfs(q, grid);
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return cnt;
    }
};
