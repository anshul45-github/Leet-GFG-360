#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        vector<pair<int, int>> directions = {{1, 1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}};
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if(p.first == grid.size() - 1 && p.second == grid.size() - 1)
                return grid[p.first][p.second];
            for(auto direction : directions) {
                int x = p.first + direction.first;
                int y = p.second + direction.second;
                if(x >= 0 && x < grid.size() && y >= 0 && y < grid.size() && grid[x][y] == 0) {
                    q.push({x, y});
                    grid[x][y] = grid[p.first][p.second] + 1;
                }
            }
        }
        return -1;
    }
};
