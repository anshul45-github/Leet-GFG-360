// TC : O(V^2), SC : O(V)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& adjList, vector<bool>& vis, int curr) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(int i = 0; i < adjList.size(); i++) {
            if(adjList[curr][i] == 1 && i != curr)
                dfs(adjList, vis, i);
        }
    }
  public:
    int numProvinces(vector<vector<int>> isConnected, int V) {
        vector<bool> vis(isConnected.size(), false);
        int cnt = 0;
        for(int i = 0; i < isConnected.size(); i++) {
            if(!vis[i]) {
                cnt++;
                dfs(isConnected, vis, i);
            }
        }
        return cnt;
    }
};
