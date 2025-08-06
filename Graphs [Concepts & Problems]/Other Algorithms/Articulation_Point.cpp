// https://www.geeksforgeeks.org/problems/articulation-point-1/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 0;
    void dfs(vector<int> adj[], vector<int>& dt, vector<int>& low, vector<bool>& vis, vector<bool>& isAp, int curr, int par) {
        dt[curr] = low[curr] = ++timer;
        int children = 0;
        vis[curr] = true;
        for(int nbr : adj[curr]) {
            if(nbr == par)
                continue;
            else if(vis[nbr]) 
                low[curr] = min(low[curr], dt[nbr]);
            else {
                children++;
                dfs(adj, dt, low, vis, isAp, nbr, curr);
                low[curr] = min(low[curr], low[nbr]);
                if(low[nbr] >= dt[curr] && par != -1)
                    isAp[curr] = true;
            }
        }
        if(par == -1 && children > 1)
            isAp[curr] = true;
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> dt(V), low(V);
        vector<bool> vis(V, false), isAp(V, false);
        dfs(adj, dt, low, vis, isAp, 0, -1);
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(isAp[i])
                ans.push_back(i);
        }
        if(ans.size() == 0)
            return {-1};
        return ans;
    }
};