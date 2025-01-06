#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfsTraversal(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& dfs, int curr) {
        if(vis[curr])
            return;
        vis[curr] = true;
        dfs.push_back(curr);
        for(int i = 0; i < adj[curr].size(); i++)
            dfsTraversal(adj, vis, dfs, adj[curr][i]);
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<bool> vis(adj.size(), false);
        vector<int> dfs;
        for(int i = 0; i < adj.size(); i++) {
            if(!vis[i])
                dfsTraversal(adj, vis, dfs, i);
        }
        return dfs;
    }
};
