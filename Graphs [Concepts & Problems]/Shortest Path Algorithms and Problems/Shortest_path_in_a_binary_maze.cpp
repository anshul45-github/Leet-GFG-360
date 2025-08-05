// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push({0, 0});
        int lvl = 1;
        while(!q.empty()) {
            int sz = q.size();
            for(int k = 0; k < sz; k++) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(grid[i][j] != 0)
                    continue;
                grid[i][j] = 2;
                if(i == n - 1 && j == n - 1)
                    return lvl;
                for(auto& direction : directions) {
                    int ni = i + direction[0];
                    int nj = j + direction[1];
                    if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 0)
                        q.push({ni, nj});
                }
            }
            lvl++;
        }
        return -1;
    }
};