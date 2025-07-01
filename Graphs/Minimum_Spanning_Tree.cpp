// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<bits/stdc++.h>
using namespace std;

// Kruskal's Algorithm
class Solution {
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++)
                edges.push_back({adj[i][j][1], i, adj[i][j][0]});
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(V);
        int ans = 0;
        for(int i = 0; i < V; i++)
            parent[i] = i;
        for(auto& edge : edges) {
            int u = edge[1];
            int v = edge[2];
            int w = edge[0];
            int up = find(parent, u);
            int vp = find(parent, v);
            if(up != vp) {
                ans += w;
                parent[up] = vp;
            }
        }
        return ans;
    }
};

// Prim's Algorithm
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        vector<bool> vis(V, false);
        int sum = 0;
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            if(vis[t[1]])
                continue;
            vis[t[1]] = true;
            sum += t[0];
            for(int i = 0; i < adj[t[1]].size(); i++) 
                pq.push({adj[t[1]][i][1], adj[t[1]][i][0]});
        }
        return sum;
    }
};