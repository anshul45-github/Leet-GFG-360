// https://leetcode.com/problems/path-with-minimum-effort/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int d = v[0], i = v[1], j = v[2];
            if(d > dist[i][j])
                continue;
            if(i == heights.size() - 1 && j == heights[0].size() - 1)
                return d;
            for(auto& direction : directions) {
                int ni = i + direction[0], nj = j + direction[1];
                if(ni >= 0 && nj >= 0 && ni < heights.size() && nj < heights[ni].size()) {
                    int distance = max(d, abs(heights[ni][nj] - heights[i][j]));
                    if(distance < dist[ni][nj]) {
                        dist[ni][nj] = distance;
                        pq.push({dist[ni][nj], ni, nj});
                    }
                }
            }
        }
        return -1;
    }
};