// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return parent[i];
        return parent[i] = find(parent, parent[i]);
    }
    void Union(int u, int v, vector<int>& parent, vector<int>& size) {
        if(u == v)
            return;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = stones[0][0], maxCol = stones[0][1];
        for(int i = 1; i < stones.size(); i++) {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }
        vector<int> parent(maxRow + maxCol + 2);
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
        vector<int> size(maxRow + maxCol + 2, 1);
        for(auto& stone : stones) {
            int u = stone[0], v = stone[1] + maxRow + 1;
            int up = find(parent, u), vp = find(parent, v);
            Union(up, vp, parent, size);
        }
        unordered_set <int> parents;

        for(auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            parents.insert(find(parent, nodeRow));
            parents.insert(find(parent, nodeCol));
        }
        return stones.size() - parents.size();
    }
};