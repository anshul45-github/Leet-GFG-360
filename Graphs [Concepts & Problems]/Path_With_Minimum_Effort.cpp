// https://leetcode.com/problems/path-with-minimum-effort/
// Medium

// Given a 2D array heights representing the height of each cell in a grid, return the minimum effort required to move from the top-left cell to the bottom-right cell.

// The effort is defined as the maximum absolute difference in heights between two adjacent cells.

// Two cells are considered adjacent if they are horizontally or vertically neighboring.

// Example 1:
// Input: heights = [[1,2,3],[3,2,1],[1,2,3]]
// Output: 1

// Example 2:
// Input: heights = [[1,2,3],[3,4,5],[5,6,7]]
// Output: 2

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            if(v[1] == heights.size() - 1 && v[2] == heights[0].size() - 1)
                return v[0];
            for(auto& direction : directions) {
                int x = v[1] + direction[0];
                int y = v[2] + direction[1];
                if(x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size()) {
                    int d = max(v[0], abs(heights[x][y] - heights[v[1]][v[2]]));
                    if(d < dist[x][y]) {
                        dist[x][y] = d;
                        pq.push({d, x, y});
                    }
                }
            }
        }
        return 0;
    }
};