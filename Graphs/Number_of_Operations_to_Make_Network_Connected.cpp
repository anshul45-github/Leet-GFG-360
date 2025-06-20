// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        int cnt = 0;
        for(auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            int up = find(parent, u);
            int vp = find(parent, v);
            if(up != vp) {
                parent[up] = vp;
                cnt++;
            }
        }
        return n - cnt - 1;
    }
};