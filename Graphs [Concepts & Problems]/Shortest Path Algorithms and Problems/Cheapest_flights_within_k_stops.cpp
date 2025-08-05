// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto& flight : flights)
            adj[flight[0]].push_back({flight[1], flight[2]});
        queue<vector<int>> pq;
        vector<int> prices(n, INT_MAX);
        pq.push({0, 0, src});
        prices[src] = 0;
        while(!pq.empty()) {
            auto v = pq.front();
            pq.pop();
            int stops = v[0], price = v[1], station = v[2];
            for(auto& p : adj[station]) {
                int next = p[0], localPrice = p[1];
                if(price + localPrice < prices[next] && stops <= k) {
                    prices[next] = price + localPrice;
                    pq.push({stops + 1, prices[next], next});
                }
            }
        }
        if(prices[dst] == INT_MAX)
            return -1;
        return prices[dst];
    }
};