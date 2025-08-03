#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<pair<int, int>>> printGraph(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        return adjList;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj = printGraph(n + 1, times);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        vector<int> dist(adj.size(), INT_MAX);
        dist[k] = 0;
        while(!q.empty()) {
            pair<int, int> curr = q.top();
            q.pop();
            if(curr.first > dist[curr.second])
                continue;
            for(int i = 0; i < adj[curr.second].size(); i++) {
                pair<int, int> p = adj[curr.second][i];
                if(dist[p.first] > dist[curr.second] + p.second) {
                    dist[p.first] = dist[curr.second] + p.second;
                    q.push({dist[p.first], p.first});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1; i < adj.size(); i++) {
            if(dist[i] == INT_MAX)
                return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
