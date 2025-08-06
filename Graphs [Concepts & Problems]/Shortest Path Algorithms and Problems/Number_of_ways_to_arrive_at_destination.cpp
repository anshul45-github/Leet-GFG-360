// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adj(n);
        for(auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            long long d = v[0], u = v[1];
            if(d > dist[u])
                continue;
            for(auto& n : adj[u]) {
                int v = n[0], w = n[1];
                if(dist[v] > dist[u] + 1LL * w) {
                    dist[v] = dist[u] + 1LL * w;
                    pq.push({dist[v], v});
                    ways[v] = ways[u];
                }
                else if(dist[v] == dist[u] + w) {
                    ways[v] += ways[u];
                    ways[v] %= mod;
                }
            }
        }
        return ways.back();
    }
};