#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while(i < n - 1) {
            if(intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i][1] = max(intervals[i + 1][1], intervals[i][1]);
                intervals.erase(intervals.begin() + i + 1);
                n--;
            }
            else
                i++;
        }
        return intervals;
    }
};
