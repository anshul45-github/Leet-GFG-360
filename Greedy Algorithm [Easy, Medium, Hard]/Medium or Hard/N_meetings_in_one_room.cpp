// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(pair<int, int> p1, pair<int, int> p2) {
        if(p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first < p2.first;
    }
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> v;
        for(int i = 0; i < start.size(); i++)
            v.push_back({start[i], end[i]});
        sort(v.begin(), v.end(), cmp);
        int l = v[0].first;
        int r = v[0].second;
        int cnt = 1;
        for(int i = 1; i < v.size(); i++) {
            int s = v[i].first;
            int e = v[i].second;
            if(s > r) {
                l = s;
                r = e;
                cnt++;
            }
            else if(s >= l && e <= r) {
                l = s;
                r = e;
            }
        }
        return cnt;
    }
};
