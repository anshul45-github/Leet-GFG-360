// https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<pair<int, int>>>& adj, int start, int k) {
        vector<int> dist(adj.size(), 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int u = p.second;
            // cout << d << " " << u << edl;
            if(d > dist[u])
                continue;
            for(auto& n : adj[u]) {
                int v = n.first;
                int w = n.second;
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < dist.size(); i++) {
            // cout << dist[i] << " ";
            if(dist[i] <= k)
                cnt++;
        }
        // cout << endl;
        return cnt;
    }
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = 0;
        int miniCities = INT_MAX;
        vector<vector<pair<int, int>>> adj(n);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        for(int i = 0; i < n; i++) {
            int cities = solve(adj, i, distanceThreshold);
            // cout << cities << " ";
            if(cities <= miniCities) {
                miniCities = cities;
                ans = i;
            }
        }
        return ans;
    }
};
