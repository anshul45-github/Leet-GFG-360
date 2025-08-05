// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        vector<int> dist(adj.size(), -1);
        queue<int> q;
        q.push(src);
        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int u = q.front();
                q.pop();
                if(dist[u] != -1)
                    continue;
                dist[u] = lvl;
                for(int n : adj[u]) 
                    q.push(n);
            }
            lvl++;
        }
        return dist;
    }
};