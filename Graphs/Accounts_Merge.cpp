// https://leetcode.com/problems/accounts-merge/
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        vector<int> parent(accounts.size());
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(!mp.count(accounts[i][j])) 
                    mp[accounts[i][j]] = i;
                int up = find(parent, i);
                int vp = find(parent, mp[accounts[i][j]]);
                if(up != vp)
                    parent[up] = vp;
            }
        }
        vector<set<string>> ans;
        unordered_map<int, int> mapping;
        for(int i = 0; i < accounts.size(); i++) {
            int p = find(parent, mp[accounts[i][1]]);
            if(!mapping.count(p)) {
                mapping[p] = ans.size();
                ans.push_back(set<string>());
            }
            for(int j = 1; j < accounts[i].size(); j++) {
                ans[mapping[p]].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> temp(ans.size());
        for(int i = 0; i < accounts.size(); i++) {
            int p = mapping[find(parent, i)];
            if(!temp[p].size())
                temp[p].push_back(accounts[i][0]);
        }
        for(int i = 0; i < ans.size(); i++) {
            for(string x : ans[i])
                temp[i].push_back(x);
        }
        return temp;
    }
};