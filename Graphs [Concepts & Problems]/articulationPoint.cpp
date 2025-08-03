// TC : O(V + E), SC : O(V)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int curr, int par, int& t, vector<int>& dt, vector<int>& low, vector<int> adj[], vector<bool>&v) {
        dt[curr] = low[curr] = ++t;
        int children = 0;
        for(int i = 0; i < adj[curr].size(); i++) {
            int n = adj[curr][i];
            if(n == par)
                continue;
            else if(dt[n] == -1) {
                dfs(n, curr, t, dt, low, adj, v);
                low[curr] = min(low[curr], low[n]);
                if(par != -1 && dt[curr] <= low[n])
                    v[curr] = true;
                children++;
            }
            else {
                low[curr] = min(low[curr], dt[n]);
            }
        }
        if(par == -1 && children > 1)
            v[curr] = true;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> dt(V, -1);
        vector<int> low(V, -1);
        vector<bool> v(V, false);
        int t = 0;
        for(int i = 0; i < V; i++) {
            if(dt[i] == -1)
                dfs(i, -1, t, dt, low, adj, v);
        }
        vector<int> a;
        for(int i = 0; i < V; i++) {
            if(v[i])
                a.push_back(i);
        }
        if(a.size() == 0)
            a.push_back(-1);
        return a;
    }
};
