// https://leetcode.com/problems/count-the-number-of-complete-components/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    bool isCompleteConnected(vector<unordered_set<int>>& adj, vector<bool>& vis, int curr) {
        auto& s = adj[curr];
        for(int n : s) 
            vis[n] = true;
        for(int n : s) {
            if(adj[n].size() != s.size())
                return false;
            for(int x : adj[n]) {
                if(!s.count(x))
                    return false;
            }
        }
        return true;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        for(auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        for(int i = 0; i < n; i++)
            adj[i].insert(i);
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i])
                continue;
            ans += isCompleteConnected(adj, vis, i);
        }
        return ans;
    }
};