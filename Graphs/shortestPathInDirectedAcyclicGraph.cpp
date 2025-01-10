#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<pair<int, int>>> printGraph(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(V);
        for(int i = 0; i < edges.size(); i++)
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        return adjList;
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj = printGraph(V, edges);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int src = 0;
        q.push({0, src});
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        while(!q.empty()) {
            pair<int, int> curr = q.top();
            q.pop();
            if(curr.first > dist[curr.second])
                continue;
            for(const auto& n : adj[curr.second]) {
                if(dist[n.first] > n.second + curr.first) {
                    dist[n.first] = n.second + curr.first;
                    q.push({dist[n.first], n.first});
                }
            }
        }
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};
