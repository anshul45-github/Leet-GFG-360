#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, vector<pair<int, int>>> printGraph(vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(int i = 0; i < edges.size(); i++)
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        return adjList;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<vector<int>> q;
        q.push({0, src, 0});
        unordered_map<int, int> dist;
        dist[src] = 0;
        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            if(curr[2] > k)
                continue;
            for(auto& n : adj[curr[1]]) {
                if((!dist.count(n.first) || curr[0] + n.second < dist[n.first])) {
                    dist[n.first] = curr[0] + n.second;
                    q.push({curr[0] + n.second, n.first, curr[2] + 1});
                }
            }
        }
        return dist.count(dst) ? dist[dst] : -1;
    }
};
