#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int mini = newInterval[0];
        int maxi = newInterval[1];
        if(intervals.size() == 0)
            return {{mini, maxi}};
        for(int i = 0; i < intervals.size(); i++) {
            if((intervals[i][0] <= mini && mini <= intervals[i][1]) || (mini <= intervals[i][0] && intervals[i][1] <= maxi) || (intervals[i][0] <= maxi && maxi <= intervals[i][1])) {
                mini = min(mini, intervals[i][0]);
                maxi = max(maxi, intervals[i][1]);
            }
        }
        int i = 0;
        bool first = false;
        while(i < intervals.size()) {
            if(mini <= intervals[i][0] && intervals[i][1] <= maxi) {
                if(!first) {
                    intervals[i] = {mini, maxi};
                    first = true;
                    i++;
                }
                else
                    intervals.erase(intervals.begin() + i);
            }
            else
                i++;
        }
        if(!first) {
            for(int i = 0; i < intervals.size(); i++) {
                if((i - 1 >= 0 ? intervals[i - 1][0] : -1) < mini && intervals[i][0] > mini) {
                    intervals.insert(intervals.begin() + i, {mini, maxi});
                    first = true;
                }
            }
        }
        if(!first)
            intervals.push_back({mini, maxi});
        return intervals;
    }
};
