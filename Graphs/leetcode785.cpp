#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfsTraversal(vector<vector<int>>& adj, vector<int>& color, int curr, int col) {
        if(color[curr] != -1)
            return true;
        color[curr] = col;
        for(int i = 0; i < adj[curr].size(); i++) {
            int n = adj[curr][i];
            if(color[n] == col)
                return false;
            if(!dfsTraversal(adj, color, n, col == 0 ? 1 : 0))
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == -1) {
                if(!dfsTraversal(graph, color, i, 0))
                    return false;
            }
        }
        return true;
    }
};
