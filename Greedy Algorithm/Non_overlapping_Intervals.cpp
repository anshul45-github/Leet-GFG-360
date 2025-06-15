// https://leetcode.com/problems/non-overlapping-intervals/
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(vector<int>& p1, vector<int>& p2) {
        return p1[1] < p2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int prev = 0;
        int cnt = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= intervals[prev][1]) {
                prev = i;
                cnt++;
            }
        }
        return n - cnt;
    }
};
