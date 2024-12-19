#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> solns;
    void solve(string currPath, vector<vector<int>>& mat, int i, int j, vector<vector<bool>>& vis) {
        if(i == mat.size() - 1 && j == mat.size() - 1) {
            solns.push_back(currPath);
            return;
        }
        if(i < 0 || i >= mat.size() || j < 0 || j >= mat.size() || !mat[i][j] || vis[i][j])
            return;
        vis[i][j] = true;
        solve(currPath + "D", mat, i + 1, j, vis);
        solve(currPath + "U", mat, i - 1, j, vis);
        solve(currPath + "L", mat, i, j - 1, vis);
        solve(currPath + "R", mat, i, j + 1, vis);
        vis[i][j] = false;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<vector<bool>> vis(mat.size(), vector<bool>(mat.size(), false));
        solve("", mat, 0, 0, vis);
        return solns;
    }
};
