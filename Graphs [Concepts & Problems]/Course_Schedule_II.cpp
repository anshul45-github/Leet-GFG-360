// https://leetcode.com/problems/course-schedule-ii/

#include<bits/stdc++.h>
using namespace std;

// Approach: Kahn's Algorithm (BFS)
class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
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
        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto n : adj[u]) {
                if(--indegree[n] == 0)
                    q.push(n);
            }
            ans.push_back(u);
            // v++;
        }
        if(ans.size() != V)
            return {};
        return ans;
    }
};

// Approach: DFS with Cycle Detection
class Solution {
    bool dfsTraversal(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& dfs, int curr, vector<bool>& rec) {
        vis[curr] = true;
        rec[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++) {
            if(rec[adj[curr][i]])
                return true;
            if(!vis[adj[curr][i]]) {
                if(dfsTraversal(adj, vis, dfs, adj[curr][i], rec))
                    return true;
            }
        }
        rec[curr] = false;
        dfs.push_back(curr);
        return false;
    }
public:
    vector<vector<int>> printGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        return adjList;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = printGraph(numCourses, prerequisites);
        vector<bool> vis(numCourses, false);
        vector<int> dfs;
        vector<bool> rec(numCourses, false);
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i] && dfsTraversal(adj, vis, dfs, i, rec)) {
                vector<int> v;
                return v;
            }
        }
        reverse(dfs.begin(), dfs.end());
        return dfs;
    }
};