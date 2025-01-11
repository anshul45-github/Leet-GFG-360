#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int curr) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++)
            dfs(adj, vis, adj[curr][i]);
    }
    vector<vector<int>> printGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(auto v : edges) {
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
        }
        return adjList;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj = printGraph(n, connections);
        vector<bool> vis(n, false);
        int connected = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(adj, vis, i);
                connected++;
            }
        }
        return connected - 1;
    }
};
