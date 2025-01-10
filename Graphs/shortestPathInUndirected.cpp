#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        queue<int> q;
        q.push(src);
        vector<int> dist(adj.size(), INT_MAX);
        vector<bool> vis(adj.size(), false);
        dist[src] = 0;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            vis[curr] = true;
            for(int i = 0; i < adj[curr].size(); i++) {
                int n = adj[curr][i];
                if(!vis[n]) {
                    dist[n] = min(dist[curr] + 1, dist[n]);
                    q.push(n);
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
