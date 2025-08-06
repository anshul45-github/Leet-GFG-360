// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
    void Union(int u, int v, vector<int>& parent, vector<int>& rank) {
        if(rank[u] < rank[v]) 
            parent[u] = v;
        else if(rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[u] = v;
            rank[v]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);\
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        vector<int> rank(n, 0);
        int groups = n;
        for(auto& connection : connections) {
            int u = find(parent, connection[0]), v = find(parent, connection[1]);
            if(u != v) {
                groups--;
                Union(u, v, parent, rank);
            }
        }
        return groups - 1;
    }
};