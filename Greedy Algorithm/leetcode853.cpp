#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        vector<pair<int, int>> v;
        for(int i = 0; i < p.size(); i++) {
            v.push_back({p[i], s[i]});
        }
        sort(v.begin(), v.end());
        int fleets = 0;
        int i = v.size() - 1;
        while(i >= 0) {
            float d = t - v[i].first;
            float time = d / v[i].second;
            int j = i - 1;
            while(j >= 0) {
                float newD = t - v[j].first;
                float newT = newD / v[j].second;
                if(newT > time)
                    break;
                j--;
            }
            fleets++;
            i = j;
        }
        return fleets;
    }
};