#include<bits/stdc++.h>
using namespace std;

class Solution {
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    bool checkAtlantic(vector<vector<int>>& heights, int i, int j) {
        if(i == heights.size() - 1 || j == heights[0].size() - 1)
            return true;
        if(heights[i][j] == -1)
            return false;
        for(int k = 0; k < 4; k++) {
            int nx = i + x[k];
            int ny = j + y[k];
            if(nx < 0 || nx >= heights.size() || ny < 0 || ny >= heights[0].size())
                continue;
            if(heights[nx][ny] <= heights[i][j]) {
                int temp = heights[i][j];
                heights[i][j] = -1;
                if(checkAtlantic(heights, nx, ny)) {
                    heights[i][j] = temp;
                    return true;
                }
                heights[i][j] = temp;
            }
        }
        return false;
    }
    bool checkPacific(vector<vector<int>>& heights, int i, int j) {
        if(i == 0 || j == 0)
            return true;
        if(heights[i][j] == -1)
            return false;
        for(int k = 0; k < 4; k++) {
            int nx = i + x[k];
            int ny = j + y[k];
            if(nx < 0 || nx >= heights.size() || ny < 0 || ny >= heights[0].size())
                continue;
            if(heights[nx][ny] <= heights[i][j]) {
                int temp = heights[i][j];
                heights[i][j] = -1;
                if(checkPacific(heights, nx, ny)) {
                    heights[i][j] = temp;
                    return true;
                }
                heights[i][j] = temp;
            }
        }
        return false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        for(int i = 0; i < heights.size(); i++) {
            for(int j = 0; j < heights[0].size(); j++) {
                if(checkPacific(heights, i, j) && checkAtlantic(heights, i, j))
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};