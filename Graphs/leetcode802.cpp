#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> transpose(vector<vector<int>>& graph, vector<int>& indegree) {
        vector<vector<int>> transposedGraph(graph.size());
        for(int i = 0; i < graph.size(); i++) {
            indegree[i] = graph[i].size();
            for(int j = 0; j < graph[i].size(); j++) {
                transposedGraph[graph[i][j]].push_back(i);
            }
        }
        return transposedGraph;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size());
        graph = transpose(graph, indegree);
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int i = 0; i < graph[curr].size(); i++) {
                if(--indegree[graph[curr][i]] == 0)
                    q.push(graph[curr][i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
