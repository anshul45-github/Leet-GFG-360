// https://leetcode.com/problems/01-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> grid(mat.size(), vector<int>(mat[0].size(), -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for(auto& d : directions) {
                int ni = i + d[0];
                int nj = j + d[1];
                if(ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[ni].size() && grid[ni][nj] == -1) {
                    grid[ni][nj] = grid[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        return grid;
    }
};