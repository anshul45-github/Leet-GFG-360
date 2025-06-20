// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Medium

// Problem Statement:
// There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
// Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, return -1.

// Example:
// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200

// Constraints:
// 1 <= n <= 100
// flights[i].length == 3
// 0 <= u, v < n
// u != v
// 0 <= price <= 10000
// There will not be any multiple flights between two cities.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); i++) 
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        vector<int> distance(n, INT_MAX);
        queue<vector<int>> q;
        q.push({src, 0, 0});
        distance[src] = 0;
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            int u = v[0];
            int dist = v[1];
            int stops = v[2];
            for(auto& n : adj[u]) {
                if(distance[n.first] > v[1] + n.second && stops <= k) {
                    distance[n.first] = v[1] + n.second;
                    q.push({n.first, distance[n.first], stops + 1});
                }
            }
        }
        if(distance[dst] == INT_MAX)
            return -1;
        return distance[dst];
    }
};