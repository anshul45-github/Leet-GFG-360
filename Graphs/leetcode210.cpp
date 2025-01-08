#include<bits/stdc++.h>
using namespace std;

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
