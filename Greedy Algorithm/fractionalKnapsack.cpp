#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(pair<double, int> p1, pair<double, int> p2) {
        return p1.first > p2.first;
    }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, int>> v(val.size());
        for(int i = 0; i < val.size(); i++)
            v[i] = {(double)val[i] / (double)wt[i], i};
        sort(v.begin(), v.end(), cmp);
        double totalVal = 0;
        int i = 0;
        while(capacity && i < v.size()) {
            int idx = v[i].second;
            if(capacity >= wt[idx]) {
                capacity -= wt[idx];
                totalVal += (double)val[idx];
            }
            else {
                totalVal += capacity * (double)v[i].first;
                capacity = 0;
            }
            i++;
        }
        return totalVal;
    }
};
