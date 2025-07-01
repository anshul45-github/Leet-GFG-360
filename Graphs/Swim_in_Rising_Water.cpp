#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(grid.size(), vector<int>(grid.size(), INT_MAX));
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            if(v[1] == grid.size() - 1 && v[2] == grid.size() - 1)
                return v[0];
            for(auto direction : directions) {
                int x = v[1] + direction[0];
                int y = v[2] + direction[1];
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid.size()) {
                    int d = max(v[0], grid[x][y]);
                    if(dist[x][y] > d) {
                        dist[x][y] = d;
                        pq.push({d, x, y});
                    }
                }
            }
        }
        return 0;
    }
};