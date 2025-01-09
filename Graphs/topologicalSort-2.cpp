#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int> indegree(adj.size(), 0);
        for(int i = 0; i < adj.size(); i++) {
            for(int j = 0; j < adj[i].size(); j++)
                indegree[adj[i][j]]++;
        }
        queue<int> q;
        for(int i = 0; i < adj.size(); i++) {
            if(!indegree[i])
                q.push(i);
        }
        vector<int> topSort;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            topSort.push_back(curr);
            for(int i = 0; i < adj[curr].size(); i++) {
                indegree[adj[curr][i]]--;
                if(!indegree[adj[curr][i]])
                    q.push(adj[curr][i]);
            }
        }
        return topSort;
    }
};
