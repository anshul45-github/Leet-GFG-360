// https://leetcode.com/problems/critical-connections-in-a-network/

#include<bits/stdc++.h>
using namespace std;   

class Solution {
    int timer = 0;
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& adj, vector<int>& dt, vector<int>& low, int curr, vector<bool>& vis, int parent) {
        dt[curr] = low[curr] = ++timer;
        vis[curr] = true;
        for(auto& nbr : adj[curr]) {
            if(nbr == parent)
                continue;
            else if(vis[nbr])
                low[curr] = min(low[curr], low[nbr]);
            else {
                dfs(adj, dt, low, nbr, vis, curr);
                low[curr] = min(low[curr], low[nbr]);
                if(dt[curr] < low[nbr]) 
                    ans.push_back({curr, nbr});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<int> dt(n);
        vector<int> low(n);
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) 
                dfs(adj, dt, low, i, vis, -1);
        }
        return ans;
    }
};