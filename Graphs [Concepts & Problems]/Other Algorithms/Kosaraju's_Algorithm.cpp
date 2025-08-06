// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void topSort(vector<vector<int>>& adj, int curr, vector<bool>& vis, stack<int>& st) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(auto& nbr : adj[curr])
            topSort(adj, nbr, vis, st);
        st.push(curr);
    }
    void dfs(vector<vector<int>>& adj, int curr, vector<bool>& vis) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(auto& nbr : adj[curr])
            dfs(adj, nbr, vis);
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        stack<int> st;
        vector<bool> vis(adj.size(), false);
        for(int i = 0; i < adj.size(); i++) {
            if(!vis[i])
                topSort(adj, i, vis, st);
        }
        vector<vector<int>> transpose(adj.size());
        for(int i = 0; i < adj.size(); i++) {
            vis[i] = false;
            for(int j = 0; j < adj[i].size(); j++)
                transpose[adj[i][j]].push_back(i);
        }
        int cnt = 0;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if(!vis[u]) {
                dfs(transpose, u, vis);
                cnt++;
            }
        }
        return cnt;
    }
};