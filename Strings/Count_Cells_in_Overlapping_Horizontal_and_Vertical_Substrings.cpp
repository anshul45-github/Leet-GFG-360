// https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/
// 3529. Count Cells in Overlapping Horizontal and Vertical Substrings
// Medium

#include<vector>
#include<string>
using namespace std;

class Solution {
    vector<pair<int, int>> findAll(string& s, string& p) {
        vector<pair<int, int>> positions;
        int pos = s.find(p);
        while(pos != string::npos) {
            positions.push_back({pos, pos + p.size() - 1});
            pos = s.find(p, pos + 1);
        }
        return positions;
    }
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        string v = "";
        string h = "";
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++)
                h += grid[i][j];
        }
        for(int j = 0; j < grid[0].size(); j++) {
            for(int i = 0; i < grid.size(); i++)
                v += grid[i][j];
        }
        vector<pair<int, int>> hori = findAll(h, pattern);
        vector<pair<int, int>> vert = findAll(v, pattern);
        vector<int> prefixH(h.size(), 0);
        vector<int> prefixV(v.size(), 0);
        for(auto& position : hori) {
            int start = position.first;
            int end = position.second;
            if(start < h.size())
                prefixH[start]++;
            if(end + 1 < h.size())
                prefixH[end + 1]--;
        }
        for(auto& position : vert) {
            int start = position.first;
            int end = position.second;
            if(start < v.size())
                prefixV[start]++;
            if(end + 1 < v.size())
                prefixV[end + 1]--;
        }
        for(int i = 1; i < h.size(); i++) {
            prefixH[i] += prefixH[i - 1];
            prefixV[i] += prefixV[i - 1];
        }
        vector<vector<int>> revH(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> revV(grid.size(), vector<int>(grid[0].size()));
        for(int i = 0; i < h.size(); i++) {
            revH[i / grid[0].size()][i % grid[0].size()] = prefixH[i];
            revV[i % grid.size()][i / grid.size()] = prefixV[i];
        }
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(revH[i][j] && revV[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};