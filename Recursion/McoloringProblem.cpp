#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> transform(vector<pair<int, int>>& edges, int v) {
        vector<vector<int>> neg(v);
        for(int i = 0; i < edges.size(); i++) {
            pair<int, int> edge = edges[i];
            neg[edge.first].push_back(edge.second);
            neg[edge.second].push_back(edge.first);
        }
        return neg;
    }
    bool isSafe(vector<vector<int>>& adj, int curr, vector<int>& colors, int color) {
        for(int i = 0; i < adj[curr].size(); i++) {
            if(colors[adj[curr][i]] == color)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<int>> adj, int v, int n, vector<int>& colors, int curr) {
        if(curr == v)
            return true;
        
        for(int i = 0; i < n; i++) {
            if(isSafe(adj, curr, colors, i)) {
                colors[curr] = i;
                if(solve(adj, v, n, colors, curr + 1))
                    return true;
            }
        }
        
        return false;
    }
  public:
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<vector<int>> neg = transform(edges, v);
        vector<int> colors(v, -1);
        
        bool ans = solve(neg, v, m, colors, 0);
        
        return ans;
    }
};
