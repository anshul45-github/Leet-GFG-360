// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int i, int j, int basex, int basey, vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<pair<int, int>> &output, int m, int n) {
        visited[i][j] = true;
        
        output.push_back({i - basex, j - basey});
        
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for(int x = 0; x < 4; x++) {
            int newx = i + directions[x].first;
            int newy = j + directions[x].second;
            
            if(newx >= 0 && newx < m && newy >= 0 && newy < n 
                && !visited[newx][newy] && grid[newx][newy] == 1) {
                    dfs(newx, newy, basex, basey, grid, visited, output, m, n);
                }
            }
        }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> set;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1)  {
                    vector<pair<int, int>> output;
                    dfs(i, j, i, j, grid, visited, output, m, n);
                    set.insert(output);
                }
            }
        }
        
        return set.size();
    }
};