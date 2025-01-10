#include<bits/stdc++.h>
using namespace std;

class Solution {
    void shortestDistance(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++) {
            mat[i][i] = 0;
        }
        for(int a = 0; a < mat.size(); a++) {
            for(int i = 0; i < mat.size(); i++) {
                for(int j = 0; j < mat.size(); j++) {
                    mat[i][j] = min(mat[i][j], mat[i][a] + mat[a][j]);
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for(auto edge : edges) {
            adj[edge[0]][edge[1]] = edge[2];
            adj[edge[1]][edge[0]] = edge[2];
        }
        shortestDistance(adj);
        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0; i < adj.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < adj.size(); j++) {
                if(i == j)
                    continue;
                if(adj[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= mini) {
                mini = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
