// https://leetcode.com/problems/k-closest-points-to-origin/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for(int i = 0; i < points.size(); i++) {
            long long distance = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            pq.push({distance, i});
        }
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            auto p = pq.top();
            ans.push_back({points[p.second][0], points[p.second][1]});
            pq.pop();
        }
        return ans;
    }
};