#include<bits/stdc++.h>
using namespace std;

class Solution {
    string find(string& p, map<string, string>& parent) {
        if(parent[p] == p)
            return p;
        return find(parent[p], parent);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> parent;
        map<string, string> owner;
        map<string, set<string>> unions;
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                parent[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        for(int i = 0; i < accounts.size(); i++) {
            string p = find(accounts[i][1], parent);
            for(int j = 1; j < accounts[i].size(); j++) {
                parent[find(accounts[i][j], parent)] = p;
            }
        }
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                unions[find(accounts[i][j], parent)].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for(pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            ans.push_back(emails);
        }
        return ans;
    }
};
