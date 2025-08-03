// https://www.geeksforgeeks.org/problems/critical-connections/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    int Time;
    void dfs(vector<vector<int>>& adj, int curr, int par, vector<int>& dt, vector<int>& low, vector<bool>& vis) {
        Time++;
        dt[curr] = Time;
        low[curr] = Time;
        vis[curr] = true;
        for(auto& n : adj[curr]) {
            if(n == par)
                continue;
            if(!vis[n]) {
                dfs(adj, n, curr, dt, low, vis);
                if(dt[curr] < low[n])
                    ans.push_back({min(curr, n), max(curr, n)});
            }
            if(vis[n])
                low[curr] = min(low[curr], low[n]);
        }
    }
  public:
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        Time = 0;
        vector<bool> vis(v, false);
        vector<int> dt(v), low(v);
        dfs(adj, 0, -1, dt, low, vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};