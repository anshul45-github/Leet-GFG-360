// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool canFit(map<int, int>& s, int low) {
        auto it = s.lower_bound(low);
        return it != s.end() && it -> second > 0;
    }
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> v;
        v.push_back(startTime[0]);
        for(int i = 0; i < startTime.size() - 1; i++) {
            v.push_back(endTime[i] - startTime[i]);
            v.push_back(startTime[i + 1] - endTime[i]);
        }
        v.push_back(endTime.back() - startTime.back());
        v.push_back(eventTime - endTime.back());
        map<int, int> s;
        for(int i = 2; i < v.size(); i += 2)
            s[v[i]]++;
        int ans = 0;
        for(int i = 1; i < v.size(); i += 2) {
            if(--s[v[i + 1]] == 0)
                s.erase(v[i + 1]);
            if(canFit(s, v[i]))
                ans = max(ans, v[i - 1] + v[i] + v[i + 1]);
            else
                ans = max(ans, v[i - 1] + v[i + 1]);
            s[v[i - 1]]++;
        }   
        return ans;
    }
};