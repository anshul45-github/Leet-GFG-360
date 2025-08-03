#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[2] < v2[2];
    }
    int find(int i, vector<int>& parent) {
        if(parent[i] == i)
            return i;
        parent[i] = find(parent[i], parent);
        return parent[i];
    }
    void Union(int i, int j, vector<int>& parent, vector<int>& rank) {
        if(rank[i] < rank[j])
            parent[i] = j;
        else if(rank[j] < rank[i])
            parent[j] = i;
        else {
            parent[i] = j;
            rank[j]++;
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edgeList;
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            for(int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int distance = abs(x2 - x) + abs(y2 - y);
                edgeList.push_back({i, j, distance});
            }
        }
        sort(edgeList.begin(), edgeList.end(), cmp);
        int edges = 0;
        int i = 0;
        int cost = 0;
        vector<int> parent(points.size());
        vector<int> rank(points.size(), 0);
        for(int j = 0; j < points.size(); j++)
            parent[j] = j;
        while(edges < points.size() - 1) {
            auto edge = edgeList[i];
            int p1 = find(edge[0], parent);
            int p2 = find(edge[1], parent);
            if(p1 != p2) {
                Union(p1, p2, parent, rank);
                cost += edge[2];
                edges++;
            }
            i++;
        }
        return cost;
    }
};
