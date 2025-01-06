#include<bits/stdc++.h>
using namespace std;

class Solution {
    void bfsTraversal(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& bfs, int curr, queue<int>& q) {
        q.push(curr);
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            if(vis[n])
                continue;
            vis[n] = true;
            bfs.push_back(n);
            for(int i = 0; i < adj[n].size(); i++) {
                q.push(adj[n][i]);
            }
        }
    }
  public:
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<bool> vis(adj.size(), false);
        vector<int> bfs;
        queue<int> neighbours;
        bfsTraversal(adj, vis, bfs, 0, neighbours);
        return bfs;
    }
};
