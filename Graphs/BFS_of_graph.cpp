// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> q;
        q.push(0);
        vector<bool> vis(adj.size(), false);
        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(vis[u])
                continue;
            ans.push_back(u);
            vis[u] = true;
            for(int n : adj[u])
                q.push(n);
        }
        return ans;
    }
};