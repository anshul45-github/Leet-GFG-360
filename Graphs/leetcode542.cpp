#include<bits/stdc++.h>
using namespace std;

class Solution {
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
            if(i + 1 < grid.size() && grid[i + 1][j] == -1) {
                grid[i + 1][j] = grid[i][j] + 1;
                q.push({i + 1, j});
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == -1) {
                grid[i][j + 1] = grid[i][j] + 1;
                q.push({i, j + 1});
            }
            if(i >= 1 && grid[i - 1][j] == -1) {
                grid[i - 1][j] = grid[i][j] + 1;
                q.push({i - 1, j});
            }
            if(j >= 1 && grid[i][j - 1] == -1) {
                grid[i][j - 1] = grid[i][j] + 1;
                q.push({i, j - 1});
            }
        }
        return grid;
    }
};
