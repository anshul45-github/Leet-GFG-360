// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Recursion with Backtracking (TLE)
class Solution {
    vector<int> x = {-1, 1, 0, 0, -1, 1, 1, -1};
    vector<int> y = {0, 0, -1, 1, -1, 1, -1, 1};
public:
    void solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int cnt, int& ans) {
        
        int n = grid.size();
        if(i == n - 1 && j == n - 1) 
            ans = min(ans, cnt);

        for(int k = 0; k < 8; k++) {
            int nx = i + x[k];
            int ny = j + y[k];

            if(nx < n && nx >= 0 && ny < n && ny >= 0 && !visited[nx][ny] && grid[nx][ny] == 0) {
                visited[i][j] = 1;
                solve(nx, ny, grid, visited, cnt + 1, ans);
                visited[i][j] = 0;
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) 
            return -1;
        int n = grid.size();
        int cnt = 1;
        int ans = 1e9;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        solve(0, 0, grid, visited, cnt, ans);
        if(ans == 1e9) 
            return -1;
        return ans;
    }
};

// Approach 2: Djikstra Algorithm
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