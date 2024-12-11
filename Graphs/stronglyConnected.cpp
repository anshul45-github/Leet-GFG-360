// TC : O(V + E), SC : O(V + E)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void topSort(vector<vector<int>>& adj, stack<int>& st, vector<bool>& vis, int curr) {
        vis[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++) {
            int n = adj[curr][i];
            if(!vis[n])
                topSort(adj, st, vis, n);
        }
        st.push(curr);
    }
    void modifiedDFS(vector<vector<int>>& adj, vector<bool>& vis, int curr, int& scc) {
        vis[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++) {
            int n = adj[curr][i];
            if(!vis[n])
                modifiedDFS(adj, vis, n, scc);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i])
                topSort(adj, st, vis, i);
        }
        vector<vector<int>> transposed(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                transposed[adj[i][j]].push_back(i);
            }
            vis[i] = false;
        }
        int scc = 0;
        while(!st.empty()) {
            int k = st.top();
            // cout << k << endl;
            st.pop();
            if(!vis[k]) {
                modifiedDFS(transposed, vis, k, scc);
                scc++;
            }
        }
        return scc;
    }
};
