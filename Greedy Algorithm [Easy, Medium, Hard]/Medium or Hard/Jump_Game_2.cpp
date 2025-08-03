// https://leetcode.com/problems/jump-game-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> v;
        for(int i = 0; i < start.size(); i++)
            v.push_back({start[i], end[i]});
        sort(v.begin(), v.end(), cmp);
        int ans = 1;
        int currEnd = v[0].second;
        for(int i = 1; i < start.size(); i++) {
            if(v[i].first > currEnd) {
                ans++;
                currEnd = v[i].second;
            }
        }
        return ans;
    }
};