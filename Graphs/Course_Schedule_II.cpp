// https://leetcode.com/problems/course-schedule-ii/
// Medium

// Given the total number of courses and a list of prerequisite pairs, return the order in which the courses should be taken.

// If it is impossible to finish all courses, return an empty array.

// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]

// Example 2:
// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]

// Example 3:
// Input: numCourses = 1, prerequisites = []
// Output: [0]

// Example 4:
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: []
// Explanation: The prerequisites form a cycle, so it is impossible to finish all courses.

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
    vector<int> findOrderKahnsAlgorithm(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto& v : pre) {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        int visited = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            visited++;
            for(int n : adj[u]) {
                if(--indegree[n] == 0)
                    q.push(n);
            }
            ans.push_back(u);
        }
        if(visited == numCourses)
            return ans;
        return {};
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