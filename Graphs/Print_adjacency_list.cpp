// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        return adj;
    }
};