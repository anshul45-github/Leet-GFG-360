// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/
// Medium

#include <vector>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>& adj, int curr, vector<bool>& vis, int k) {
        if(vis[curr])
            return 0;
        if(k == 0)
            return 1;
        vis[curr] = true;
        int tot = 0;
        for(auto& n : adj[curr]) {
            tot += dfs(adj, n, vis, k - 1);
        }
        vis[curr] = false;
        return 1 + tot;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> adj1(edges1.size() + 1);
        vector<vector<int>> adj2(edges2.size() + 1);
        for(auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(edges1.size() + 1, false);
        vector<int> ans(edges1.size() + 1, 0);
        for(int i = 0; i < edges1.size() + 1; i++) 
            ans[i] = dfs(adj1, i, vis, k);
        int maxi = 0;
        vis.resize(edges2.size() + 1, false);
        if(k != 0) {
            for(int i = 0; i < edges2.size() + 1; i++)
                maxi = max(maxi, dfs(adj2, i, vis, k - 1));
        }
        for(int i = 0; i < edges1.size() + 1; i++)
            ans[i] += maxi;
        return ans;
    }
};