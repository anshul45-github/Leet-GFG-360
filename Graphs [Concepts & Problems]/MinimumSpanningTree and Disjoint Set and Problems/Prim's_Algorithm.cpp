// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(V);
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < adj[0].size(); i++)
            pq.push({adj[0][i][1], adj[0][i][0]});
        vector<bool> vis(V, false);
        vis[0] = true;
        int ans = 0;
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int w = v[0], u = v[1];
            if(vis[u])
                continue;
            ans += w;
            vis[u] = true;
            for(auto& n : adj[u]) {
                if(!vis[n[0]]) 
                    pq.push({n[1], n[0]});
            }
        }
        return ans;
    }
};