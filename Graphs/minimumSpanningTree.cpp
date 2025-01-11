#include<bits/stdc++.h>
using namespace std;

class Solution {
    int find(int n, vector<int>& parent) {
        if(n == parent[n])
            return n;
        return find(parent[n], parent);
    }
    void Union(int u, int v, vector<int>& rank, vector<int>& parent) {
        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else {
            rank[u]++;
            parent[v] = u;
        }
    }
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V);
        vector<int> rank(V);
        for(int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < V; i++) {
            for(auto e : adj[i]) {
                if(i < e[0])
                    pq.push({e[1], i, e[0]});
            }
        }
        int sum = 0;
        while(!pq.empty()) {
            vector<int> e = pq.top();
            pq.pop();
            int u = e[1];
            int v = e[2];
            int up = find(u, parent);
            int vp = find(v, parent);
            if(up != vp) {
                Union(up, vp, rank, parent);
                sum += e[0];
            }
        }
        return sum;
    }
};
