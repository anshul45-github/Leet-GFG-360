#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int curr = 0;
        int sum = 0;
        vector<bool> vis(V, false);
        pq.push({0, 0});
        while(!pq.empty()) {
            auto e = pq.top();
            pq.pop();
            int curr = e.second;
            if(vis[curr])
                continue;
            vis[curr] = true;
            for(auto edge : adj[curr])
                pq.push({edge[1], edge[0]});
            sum += e.first;
        }
        return sum;
    }
};
