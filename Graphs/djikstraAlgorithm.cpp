#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src});
        vector<int> dist(adj.size(), INT_MAX);
        dist[src] = 0;
        while(!q.empty()) {
            pair<int, int> curr = q.top();
            q.pop();
            if(curr.first > dist[curr.second])
                continue;
            for(int i = 0; i < adj[curr.second].size(); i++) {
                pair<int, int> n = adj[curr.second][i];
                if(dist[n.first] > dist[curr.second] + n.second) {
                    dist[n.first] = dist[curr.second] + n.second;
                    q.push({dist[n.first], n.first});
                }
            }
        }
        for(int i = 0; i < adj.size(); i++) {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};
