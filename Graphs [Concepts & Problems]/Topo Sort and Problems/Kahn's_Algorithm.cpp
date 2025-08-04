// https://www.geeksforgeeks.org/problems/topological-sort/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int n : adj[u]) {
                indegree[n]--;
                if(indegree[n] == 0)
                    q.push(n);
            }
            ans.push_back(u);
        }
        return ans;
    }
};