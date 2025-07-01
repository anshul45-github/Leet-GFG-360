// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - DFS
class Solution {
    int dfs(vector<vector<int>>& stones, vector<bool>& vis, int curr) {
        if(vis[curr])
            return 0;
        vis[curr] = true;
        int ans = 1;
        for(int i = 0; i < stones.size(); i++) {
            if((stones[i][0] != stones[curr][0] && stones[i][1] != stones[curr][1]) || vis[i])
                continue;
            ans += dfs(stones, vis, i);
        }
        return ans;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> vis(stones.size(), false);
        int ans = 0;
        for(int i = 0; i < stones.size(); i++) {
            if(!vis[i])
                ans += dfs(stones, vis, i) - 1;
        }
        return ans;
    }
};

// Approach 2 - Disjoint Set Union-Find
class Solution {
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        for(auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        vector<int> parent(maxRow + maxCol + 2);
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
        unordered_map<int, bool> stoneNodes;

        for(auto& stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1;

            int u = find(parent, rowNode);
            int v = find(parent, colNode);
            if(u != v)
                parent[u] = v;
            stoneNodes[rowNode] = true;
            stoneNodes[colNode] = true;
        }

        int numComponents = 0;
        for(auto& node : stoneNodes) {
            if(find(parent, node.first) == node.first) 
                numComponents++;
        }

        return n - numComponents;
    }
};