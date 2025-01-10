#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        dist[0][0] = 0;
        while(!q.empty()) {
            vector<int> curr = q.top();
            q.pop();
            if(curr[1] == heights.size() - 1 && curr[2] == heights[0].size() - 1)
                return curr[0];
            for(auto direction : directions) {
                int x = curr[1] + direction.first;
                int y = curr[2] + direction.second;
                if(x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size()) {
                    int d = max(curr[0], abs(heights[x][y] - heights[curr[1]][curr[2]]));
                    if(d < dist[x][y]) {
                        dist[x][y] = d;
                        q.push({d, x, y});
                    }
                }
            }
        }
        return 0;
    }
};
