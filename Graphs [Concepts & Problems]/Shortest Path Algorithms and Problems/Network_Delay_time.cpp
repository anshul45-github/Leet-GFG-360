// https://leetcode.com/problems/network-delay-time/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto& time : times)
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        vector<int> Time(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, k - 1});
        Time[k - 1] = 0;
        while(!pq.empty()) {
            int t = pq.top()[0], u = pq.top()[1];
            pq.pop();
            if(t > Time[u])
                continue;
            for(auto& p : adj[u]) {
                int v = p[0], w = p[1];
                if(Time[v] > t + w) {
                    Time[v] = t + w;
                    pq.push({Time[v], v});
                }
            }
        }
        int maxTime = INT_MIN;
        for(int i = 0; i < n; i++) 
            maxTime = max(maxTime, Time[i]);
        if(maxTime == INT_MAX)
            return -1;
        return maxTime;
    }
};