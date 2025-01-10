#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i = 0; i < V - 1; i++) {
            for(auto edge : edges) {
                if(dist[edge[0]] != 1e8)
                    dist[edge[1]] = min(dist[edge[1]], dist[edge[0]] + edge[2]);
            }
        }
        for(auto edge : edges) {
            if(dist[edge[0]] != 1e8 && dist[edge[1]] > dist[edge[0]] + edge[2]) {
                return {-1};
            }
        }
        return dist;
    }
};
