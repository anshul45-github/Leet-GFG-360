// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

// Here we are using DFS to find the topological order of the DAG instead of Djikstra's algorithm as the graph is a DAG and in a DAG, the shortest path can be found using topological sorting and is more efficient than Djikstra's algorithm.

class Solution {
    void dfs(vector<vector<vector<int>>>& adj, int curr, vector<bool>& vis, stack<int>& st) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(auto n : adj[curr])
            dfs(adj, n[0], vis, st);
        st.push(curr);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(V);
        for(auto& e : edges) 
            adj[e[0]].push_back({e[1], e[2]});
        stack<int> st;
        vector<bool> vis(V, false);
        dfs(adj, 0, vis, st);
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while(!st.empty()) {
            int u = st.top();
            if(dist[u] == INT_MAX)
                continue;
            for(auto n : adj[u])
                dist[n[0]] = min(dist[n[0]], dist[u] + n[1]);
            st.pop();
        }
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};