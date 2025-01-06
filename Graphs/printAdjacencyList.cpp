#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i].first].push_back(edges[i].second);
            adjList[edges[i].second].push_back(edges[i].first);
        }
        return adjList;
    }
};
