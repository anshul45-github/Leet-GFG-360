// https://leetcode.com/problems/find-right-interval/
// Medium

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int findCeil(vector<vector<int>>& intervals, int x) {
        int l = 0;
        int r = intervals.size() - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(intervals[mid][0] == x)
                return intervals[mid][2];
            else if(intervals[mid][0] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if(l == intervals.size())
            return -1;
        return intervals[l][2];
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size());
        for(int i = 0; i < intervals.size(); i++)
            intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end());
        for(auto& interval : intervals) 
            ans[interval[2]] = findCeil(intervals, interval[1]);
        return ans;
    }
};