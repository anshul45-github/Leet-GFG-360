#include<bits/stdc++.h>
using namespace std;

class Solution {
    void modifyConnections(vector<vector<int>>& connections, vector<vector<int>>& el) {
        for(int i = 0; i < connections.size(); i++) {
            vector<int> e = connections[i];
            el[e[0]].push_back(e[1]);
            el[e[1]].push_back(e[0]);
        }
        return;
    }
    void dfs(vector<vector<int>>& el, int& time, vector<int>& low, vector<int>& dt, int par, vector<vector<int>>& v, int curr) {
        dt[curr] = low[curr] = ++time;
        for(int i = 0; i < el[curr].size(); i++) {
            int n = el[curr][i];
            if(n == par)
                continue;
            else if(dt[n] == -1) {
                dfs(el, time, low, dt, curr, v, n);
                low[curr] = min(low[curr], low[n]);
                if(dt[curr] < low[n])
                    v.push_back({curr, n});
            }
            else
                low[curr] = min(low[curr], dt[n]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> v;
        int time = 0;
        vector<vector<int>> edgeList(n);
        modifyConnections(connections, edgeList);
        vector<int> dt(n, -1);
        vector<int> low(n, -1);
        for(int i = 0; i < n; i++) {
            if(dt[i] == -1)
                dfs(edgeList, time, low, dt, i, v, i);
        }
        return v;
    }
};
