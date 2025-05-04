// https://leetcode.com/problems/island-perimeter/
// 463. Island Perimeter
// Easy

#include<vector>
using namespace std;

class Solution {
    int ans;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int check(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
            return 1;
        return 0;
    }
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
            return;
        for(auto& direction : directions)
            ans += check(grid, x + direction[0], y + direction[1]);
        grid[x][y] = -1;
        for(auto& direction : directions)
            dfs(grid, x + direction[0], y + direction[1]);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return ans;
                }
            }
        }
        return 0;
    }
};