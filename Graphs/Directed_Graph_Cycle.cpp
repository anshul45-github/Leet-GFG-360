// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - DFS
class Solution {
    bool dfs(vector<vector<int>>& adj, int curr, vector<bool>& vis, vector<bool>& rec) {
        if(rec[curr])
            return true;
        if(vis[curr])
            return false;
        vis[curr] = true;
        rec[curr] = true;
        for(auto n : adj[curr]) {
            if(dfs(adj, n, vis, rec))
                return true;
        }
        rec[curr] = false;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);
        vector<vector<int>> adj(V);
        for(auto& e : edges) 
            adj[e[0]].push_back(e[1]);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(adj, i, vis, rec))
                    return true;
            }
        }
        return false;
    }
};

// Approach 2 - Kahn's Algorithm (BFS)
class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        for(auto& e : edges) {
            indegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        int v = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto n : adj[u]) {
                if(--indegree[n] == 0)
                    q.push(n);
            }
            v++;
        }
        return v != V;
    }
};