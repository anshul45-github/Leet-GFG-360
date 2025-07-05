// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V, 1e9);
        vector<vector<pair<int, int>>> adj(V);
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto& n : adj[node]) {
                if(dist[n.first] > dist[node] + n.second) {
                    dist[n.first] = dist[node] + n.second;
                    pq.push({dist[n.first], n.first});
                }
            }
        }
        return dist;
   }
};