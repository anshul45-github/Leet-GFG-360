// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> q;
        q.push(0);
        vector<bool> vis(adj.size(), false);
        vis[0] = true;
        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int n : adj[u]) {
                if(!vis[n]) {
                    vis[n] = true;
                    q.push(n);
                }
            }
        }
        return ans;
    }
};