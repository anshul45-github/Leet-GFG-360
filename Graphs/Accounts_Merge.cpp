// https://leetcode.com/problems/accounts-merge/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> parent(accounts.size());
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
        unordered_map<string, int> mp;
        int n = accounts.size();
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mp.count(accounts[i][j])) {
                    int u = i;
                    int v = mp[accounts[i][j]];
                    int up = find(parent, u);
                    int vp = find(parent, v);
                    if(up != vp) {
                        parent[up] = vp;
                        n--;
                    }
                }
                else
                    mp[accounts[i][j]] = i;
            }
        }
        vector<set<string>> v;
        unordered_map<int, int> idxmp;
        for(int i = 0; i < accounts.size(); i++) {
            int p = find(parent, i);
            if(!idxmp.count(p)) {
                idxmp[p] = v.size();
                v.resize(idxmp[p] + 1);
            }
            for(int j = 1; j < accounts[i].size(); j++)
                v[idxmp[p]].insert(accounts[i][j]);
        }
        vector<vector<string>> ans(n);
        for(int i = 0; i < accounts.size(); i++) {
            int u = find(parent, i);
            int p = idxmp[u];
            if(p == -1)
                continue;
            idxmp[u] = -1;
            ans[p].push_back(accounts[i][0]);
            ans[p].insert(ans[p].end(), v[p].begin(), v[p].end());
        }
        return ans;
    }
};