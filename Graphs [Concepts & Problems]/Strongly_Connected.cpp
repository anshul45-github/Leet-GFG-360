// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& adj, int curr, vector<bool>& vis, stack<int>& st) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++)
            dfs(adj, adj[curr][i], vis, st);
        st.push(curr);
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        stack<int> st;
        vector<bool> vis(adj.size(), false);
        for(int i = 0; i < adj.size(); i++)
            dfs(adj, i, vis, st);
        vector<vector<int>> tr(adj.size());
        for(int i = 0; i < adj.size(); i++) {
            vis[i] = false;
            for(int j = 0; j < adj[i].size(); j++)
                tr[adj[i][j]].push_back(i);
        }
        stack<int> faaltu;
        int ans = 0;
        while(!st.empty()) {
            if(!vis[st.top()]) {
                dfs(tr, st.top(), vis, faaltu);
                ans++;
            }
            st.pop();
        }
        return ans;
    }
};