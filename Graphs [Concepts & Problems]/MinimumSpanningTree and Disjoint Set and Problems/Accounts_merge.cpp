// https://leetcode.com/problems/accounts-merge/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int parentFind(vector<int>& parent, int node) {
        if(parent[node] == node) 
            return node;
        return parent[node] = parentFind(parent, parent[node]); // path compression
    }
    void unionByRank(vector<int>& parent, vector<int>& rank, int u, int v) {
        int pu = parentFind(parent, u);
        int pv = parentFind(parent, v);
        if(pu == pv) 
            return;

        if(rank[pu] < rank[pv]) 
            parent[pu] = pv;
        else if(rank[pu] > rank[pv]) 
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> rank(n + 1, 0), parent(n + 1);
        for(int i = 0; i <= n; i++) 
            parent[i] = i;

        unordered_map<string, int> mapMailNode;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if(mapMailNode.find(mail) == mapMailNode.end()) 
                    mapMailNode[mail] = i;
                else {
                    // Merge them
                    unionByRank(parent, rank, i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mailsOfNode(n);

        for(auto it : mapMailNode) {
            string mail = it.first;
            int node = parentFind(parent, it.second); // Correct node will be the ultimate parent

            mailsOfNode[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(mailsOfNode[i].size()) {
                // Non empty
                sort(mailsOfNode[i].begin(), mailsOfNode[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]); // Name
                for(auto it : mailsOfNode[i]) 
                    temp.push_back(it);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};