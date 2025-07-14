// https://leetcode.com/problems/evaluate-division/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string find(unordered_map<string, string>& parent, string& i) {
        if(!parent.count(i))
            return i;
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
    double dfs(unordered_map<string, vector<pair<string, double>>>& adj, unordered_map<string, vector<pair<string, double>>>& revAdj, string& curr, string& dest, unordered_set<string>& vis) {
        if(vis.count(curr))
            return -1;
        if(curr == dest)
            return 1;
        vis.insert(curr);
        for(auto& n : adj[curr]) {
            double res = dfs(adj, revAdj, n.first, dest, vis);
            if(res != -1)
                return res * n.second;
        }
        for(auto& n : revAdj[curr]) {
            double res = dfs(adj, revAdj, n.first, dest, vis);
            if(res != -1)
                return res * n.second;
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        unordered_map<string, vector<pair<string, double>>> revAdj;
        unordered_map<string, string> parent;
        for(int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            revAdj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
            parent[equations[i][0]] = equations[i][0];
            parent[equations[i][1]] = equations[i][1];
        }
        for(int i = 0; i < equations.size(); i++) {
            string p1 = find(parent, equations[i][0]);
            string p2 = find(parent, equations[i][1]);
            if(p1 != p2)
                parent[p1] = p2;
        }
        vector<double> ans;
        for(auto& q : queries) {
            string u = q[0];
            string v = q[1];
            if(!parent.count(u) || !parent.count(v) || find(parent, u) != find(parent, v)) {
                ans.push_back(-1);
                continue;
            }
            unordered_set<string> vis;
            ans.push_back(dfs(adj, revAdj, u, v, vis));
        }
        return ans;
    }
};