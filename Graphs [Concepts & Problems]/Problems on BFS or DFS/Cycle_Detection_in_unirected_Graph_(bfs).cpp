// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool bfsTraversal(vector<vector<int>>& adj, vector<bool>& vis, int curr, queue<pair<int, int>>& q) {
        q.push({curr, -1});
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int n = p.first;
            vis[n] = true;
            for(int i = 0; i < adj[n].size(); i++) {
                if(adj[n][i] == p.second)
                    continue;
                else if(vis[adj[n][i]])
                    return true;
                else {
                    q.push({adj[n][i], n});
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        queue<pair<int, int>> q;
        vector<bool> vis(adj.size(), false);
        for(int i = 0; i < adj.size(); i++) {
            if(!vis[i] && bfsTraversal(adj, vis, i, q)) {
                return true;
            }
        }
        return false;
    }
};
