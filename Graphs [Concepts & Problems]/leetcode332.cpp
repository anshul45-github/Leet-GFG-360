#include<bits/stdc++.h>
using namespace std;

class Solution {
    void makeAdjList(vector<vector<string>>& tickets, unordered_map<string, vector<string>>& mp) {
        for(int i = 0; i < tickets.size(); i++)
            mp[tickets[i][0]].push_back(tickets[i][1]);
        for(auto& p : mp)
            sort(mp[p.first].rbegin(), mp[p.first].rend());
    }
    void dfs(unordered_map<string, vector<string>>& mp, string curr, vector<string>& ans) {
        while(!mp[curr].empty()) {
            string nxt = mp[curr].back();
            mp[curr].pop_back();
            dfs(mp, nxt, ans);
        }
        ans.push_back(curr);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> mp;
        makeAdjList(tickets, mp);
        vector<string> ans;
        dfs(mp, "JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
