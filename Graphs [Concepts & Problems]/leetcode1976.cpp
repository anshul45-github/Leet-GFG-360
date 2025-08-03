#include<bits/stdc++.h>
using namespace std;

#define N 1000000007

class Solution {
    vector<vector<pair<int, int>>> printGraph(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        return adjList;
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj = printGraph(n, roads);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0});
        vector<long long> dist(adj.size(), LONG_MAX);
        vector<int> ways(adj.size(), 0);
        ways[0] = 1;
        dist[0] = 0;
        // int ways = 0;
        while(!q.empty()) {
            pair<long long, int> curr = q.top();
            q.pop();
            if(curr.first > dist[curr.second])
                continue;
            for(int i = 0; i < adj[curr.second].size(); i++) {
                pair<int, int> p = adj[curr.second][i];
                // if(curr.second == 5)
                //     cout << p.first << endl;
                if(dist[p.first] > dist[curr.second] + 1LL * p.second) {
                    // if(p.first == n - 1) {
                    //     cout << "updated at " << curr.second << endl;
                    //     ways = 1;
                    // }
                    ways[p.first] = ways[curr.second];
                    dist[p.first] = dist[curr.second] + 1LL * p.second;
                    q.push({dist[p.first], p.first});
                }
                else if(dist[p.first] == dist[curr.second] + 1LL * p.second) {
                    ways[p.first] += ways[curr.second];
                    ways[p.first] %= N;
                }
            }
        }
        return ways[n - 1];
    }
};
