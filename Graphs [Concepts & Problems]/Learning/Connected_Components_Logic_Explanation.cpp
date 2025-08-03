// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& adj, int curr, vector<bool>& vis, vector<int>& currVector) {
        if(vis[curr])
            return;
        vis[curr] = true;
        currVector.push_back(curr);
        for(int x : adj[curr])
            dfs(adj, x, vis, currVector);
        return;
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> ans;
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                vector<int> component;
                dfs(adj, i, vis, component);
                ans.push_back(component);
            }
        }
        return ans;
    }
};