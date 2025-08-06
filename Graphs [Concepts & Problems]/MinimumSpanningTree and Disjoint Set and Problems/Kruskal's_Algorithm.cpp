// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(vector<int> a, vector<int> b) {
        return a[2] < b[2];
    }
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
    void Union(int u, int v, vector<int>& parent, vector<int>& size) {
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[v];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), cmp);
        vector<int> parent(V);
        for(int i = 0; i < V; i++)
            parent[i] = i;
        vector<int> size(V, 1);
        int ans = 0;
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int up = find(parent, u), vp = find(parent, v);
            if(up != vp) {
                ans += edge[2];
                Union(up, vp, parent, size);
            }
        }
        return ans;
    }
};