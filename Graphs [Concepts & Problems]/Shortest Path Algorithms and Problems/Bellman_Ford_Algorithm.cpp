// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i = 1; i < V; i++) {
            for(auto& edge : edges) {
                if(dist[edge[0]] != 1e8 && dist[edge[1]] > dist[edge[0]] + edge[2])
                    dist[edge[1]] = dist[edge[0]] + edge[2];
            }
        }
        for(auto& edge : edges) {
            if(dist[edge[0]] != 1e8 && dist[edge[1]] > dist[edge[0]] + edge[2])
                return {-1};
        }
        return dist;
    }
};