// Problem Name - Minimum Interval to Include Each Query
// Sheet - Neetcode 150
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>> pq;
        unordered_map<int, int> mp;
        vector<int> ans;
        vector<int> Q = queries;
        sort(intervals.begin(), intervals.end());
        sort(Q.begin(), Q.end());
        int i = 0;
        for(int q : Q) {
            for(; i < intervals.size() && intervals[i][0] <= q; i++)
                pq.push({intervals[i][0] - intervals[i][1] - 1, intervals[i][1]});
            while(pq.size() && pq.top()[1] < q)
                pq.pop();
            mp[q] = pq.size() ? -pq.top()[0] : -1;
        }
        for(int i = 0; i < Q.size(); i++)
            ans.push_back(mp[queries[i]]);
        return ans;
    }
};
