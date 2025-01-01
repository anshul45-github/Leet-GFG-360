#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        vector<pair<int, int>> v;
        for(int i = 0; i < profit.size(); i++)
            v.push_back({deadline[i], profit[i]});
        sort(v.begin(), v.end(), cmp);
        int sum = 0, cnt = 0;
        vector<int> slots(v.size(), 0);
        for(int i = 0; i < v.size(); i++) {
            int prof = v[i].second;
            int j = v[i].first - 1;
            while(j >= 0 && slots[j] != 0)
                j--;
            if(j >= 0) {
                slots[j] = prof;
                sum += prof;
                cnt++;
            }
        }
        return {cnt, sum};
    }
};
