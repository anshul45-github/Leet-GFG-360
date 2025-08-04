// https://leetcode.com/problems/find-eventual-safe-states/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<vector<int>> adj(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto n : adj[u]) {
                if(--indegree[n] == 0)
                    q.push(n);
            }
            ans.push_back(u);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};