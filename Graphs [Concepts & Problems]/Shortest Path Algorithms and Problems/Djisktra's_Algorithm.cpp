// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<bits/stdc++.h>
using namespace std;

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<vector<int>>> adj(V);
        for(auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});
        vector<int> dist(V, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p[0], u = p[1];
            for(auto& n : adj[u]) {
                int v = n[0], w = n[1];
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};