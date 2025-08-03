// https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Extra space
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> ans;
        int n = intervals.size();

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] > end) {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } 
            else 
                end = max(end, intervals[i][1]);
        }
        ans.push_back({start, end});
        return ans;
    }
};

// Approach 2: In-place modification
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int k = 0; // Index for
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[k][1] >= intervals[i][0]) { // Overlap detected
                intervals[k][1] = max(intervals[k][1], intervals[i][1]); 
            } else {
                k++;
                intervals[k] = intervals[i]; // Replace in-place
            }
        }
        
        intervals.resize(k + 1); 
        return intervals;
    }
};