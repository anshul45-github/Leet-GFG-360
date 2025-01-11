#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& stones, vector<bool>& vis, int curr, int& cnt) {
        if(vis[curr])
            return;
        vis[curr] = true;
        cnt++;
        for(int i = 0; i < stones.size(); i++) {
            if(stones[i][0] == stones[curr][0] || stones[i][1] == stones[curr][1])
                dfs(stones, vis, i, cnt);
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> vis(stones.size(), false);
        int ans = 0;
        for(int i = 0; i < stones.size(); i++) {
            if(!vis[i]) {
                int cnt = 0;
                dfs(stones, vis, i, cnt);
                ans += cnt - 1;
            }
        }
        return ans;
    }
};
