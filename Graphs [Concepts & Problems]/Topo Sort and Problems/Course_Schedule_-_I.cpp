// https://leetcode.com/problems/course-schedule/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        for(auto& e : edges) {
            indegree[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        int v = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto n : adj[u]) {
                if(--indegree[n] == 0)
                    q.push(n);
            }
            v++;
        }
        return v == V;
    }
};