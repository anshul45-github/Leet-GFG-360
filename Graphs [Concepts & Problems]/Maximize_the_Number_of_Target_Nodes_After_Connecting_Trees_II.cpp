// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/
// Hard

#include <vector>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& adj, int curr, vector<bool>& vis, vector<int>& ans, int& evenCnt) {
        if(vis[curr])
            return;
        vis[curr] = true;
        if(ans[curr] == 0)
            evenCnt++;
        for(auto& n : adj[curr]) {
            ans[n] = ans[curr] ^ 1;
            dfs(adj, n, vis, ans, evenCnt);
        }
        vis[curr] = false;
        return;
    }
    int dfsWithoutColorArray(vector<vector<int>>& adj, int curr, vector<bool>& vis, int d) {
        if(vis[curr])
            return 0;
        vis[curr] = true;
        int tot = 0;
        for(auto& n : adj[curr]) 
            tot += dfsWithoutColorArray(adj, n, vis, d + 1);
        vis[curr] = false;
        if(d % 2 == 0)
            return 1 + tot;
        return tot;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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
        vector<int> ans(edges1.size() + 1, -1);
        ans[0] = 0;
        int evenCnt = 0;
        dfs(adj1, 0, vis, ans, evenCnt);
        int oddCnt = edges1.size() + 1 - evenCnt;
        vis.resize(edges2.size() + 1, false);
        int evenCntB = 0;
        int maxi = dfsWithoutColorArray(adj2, 0, vis, 0);
        if(edges2.size() + 1 - maxi > maxi)
            maxi = edges2.size() + 1 - maxi;
        for(int i = 0; i < edges1.size() + 1; i++) {
            if(ans[i] == 0) 
                ans[i] = evenCnt + maxi;
            else
                ans[i] = oddCnt + maxi;
        }
        return ans;
    }
};