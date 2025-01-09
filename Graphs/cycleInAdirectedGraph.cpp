#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(vector<vector<int>>& adj, int V, vector<bool>& vis, vector<bool>& rec, int curr) {
        vis[curr] = true;
        rec[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++) {
            if(rec[adj[curr][i]])
                return true;
            if(dfs(adj, V, vis, rec, adj[curr][i]))
                return true;
        }
        rec[curr] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(adj, V, vis, rec, i))
                    return true;
            }
        }
        return false;
    }
};
