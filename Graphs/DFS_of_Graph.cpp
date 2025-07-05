// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> ans;
    void solve(vector<vector<int>>& adj, int curr, vector<bool>& vis) {
        if(vis[curr])
            return;
        vis[curr] = true;
        ans.push_back(curr);
        for(int n : adj[curr])
            solve(adj, n, vis);
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<bool> vis(adj.size(), false);
        solve(adj, 0, vis);
        return ans;
    }
};