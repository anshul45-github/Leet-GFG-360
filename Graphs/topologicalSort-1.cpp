#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& topSort, int curr) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++)
            dfs(adj, vis, topSort, adj[curr][i]);
        topSort.push_back(curr);
        return;
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int> topSort;
        vector<bool> vis(adj.size(), false);
        for(int i = 0; i < adj.size(); i++) {
            if(!vis[i])
                dfs(adj, vis, topSort, i);
        }
        reverse(topSort.begin(), topSort.end());
        return topSort;
    }
};
