// https://www.geeksforgeeks.org/problems/topological-sort/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& adj, int curr, vector<bool>& vis, stack<int>& st) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(auto& n : adj[curr])
            dfs(adj, n, vis, st);
        st.push(curr);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& e : edges)
            adj[e[0]].push_back(e[1]);
        vector<bool> vis(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis[i])
                dfs(adj, i, vis, st);
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};