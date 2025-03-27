#include<bits/stdc++.h>
using namespace std;

class Solution {
    void join(vector<int>& parent, int x, int y) {
        parent[y] = x;
    }
    int find(vector<int>& parent, int i) {
        if(i == parent[i])
            return i;
        return parent[i] = find(parent, parent[i]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1);
        for(int i = 1; i <= edges.size(); i++)
            parent[i] = i;
        for(auto edge : edges) {
            int x = find(parent, edge[0]);
            int y = find(parent, edge[1]);
            if(x == y)
                return edge;
            join(parent, x, y);
        }
        return {-1, -1};
    }
};