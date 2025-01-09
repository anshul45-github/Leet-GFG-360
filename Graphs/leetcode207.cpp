#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(vector<vector<int>>& adj, int V, vector<bool>& vis, vector<bool>& rec, int curr) {
        vis[curr] = true;
        rec[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++) {
            if(rec[adj[curr][i]])
                return true;
            if(!vis[adj[curr][i]] && dfs(adj, V, vis, rec, adj[curr][i]))
                return true;
        }
        rec[curr] = false;
        return false;
    }
    vector<vector<int>> printGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        return adjList;
    }
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = printGraph(V, prerequisites);
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(adj, V, vis, rec, i))
                    return false;
            }
        }
        return true;
    }
};
