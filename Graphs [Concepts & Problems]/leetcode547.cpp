#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> printGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            for(int j = 0; j < edges.size(); j++) {
                if(i == j)
                    continue;
                if(edges[i][j] == 1)
                    adjList[i].push_back(j);
            }
        }
        return adjList;
    }
    void dfs(vector<vector<int>>& adjList, vector<bool>& vis, int curr) {
        if(vis[curr])
            return;
        vis[curr] = true;
        for(int i = 0; i < adjList[curr].size(); i++) {
            dfs(adjList, vis, adjList[curr][i]);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> vis(isConnected.size(), false);
        vector<vector<int>> adjList = printGraph(isConnected.size(), isConnected);
        int cnt = 0;
        for(int i = 0; i < isConnected.size(); i++) {
            if(!vis[i]) {
                cnt++;
                dfs(adjList, vis, i);
            }
        }
        return cnt;
    }
};
