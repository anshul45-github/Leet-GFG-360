// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - DFS
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

// Approach 2 - Disjoint Set Union (DSU) or Union-Find
class Solution {
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        int cnt = 0;
        for(auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            int up = find(parent, u);
            int vp = find(parent, v);
            if(up != vp) {
                parent[up] = vp;
                cnt++;
            }
        }
        return n - cnt - 1;
    }
};