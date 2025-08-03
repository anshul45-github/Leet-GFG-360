// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfsTraversal(vector<vector<int>>& adj, vector<bool>& vis, int curr, int parent) {
        vis[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++) {
            if(adj[curr][i] == parent) {
                continue;
            }
            else if(vis[adj[curr][i]])
                return true;
            else {
                if(dfsTraversal(adj, vis, adj[curr][i], curr))
                    return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        vector<bool> vis(adj.size(), false);
        for(int i = 0; i < adj.size(); i++) {
            if(!vis[i]) {
                if(dfsTraversal(adj, vis, i, -1) == true)
                    return true;
            }
        }
        return false;
    }
};
