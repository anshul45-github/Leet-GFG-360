// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& start, vector<int>& end, vector<int>& val, int i, int k, vector<vector<int>>& dp) {
        if(i >= start.size() || k == 0)
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        int exclude = solve(start, end, val, i + 1, k, dp);
        auto it = lower_bound(start.begin() + i + 1, start.end(), end[i]);
        int idx = it - start.begin();
        while(idx < start.size() && start[idx] == end[i])
            idx++;
        int include = solve(start, end, val, idx, k - 1, dp) + val[i];
        return dp[i][k] = max(include, exclude);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<int> start;
        vector<int> end;
        vector<int> val;
        for(auto& e : events) {
            start.push_back(e[0]);
            end.push_back(e[1]);
            val.push_back(e[2]);
        }
        vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, -1));
        return solve(start, end, val, 0, k, dp);
    }
};