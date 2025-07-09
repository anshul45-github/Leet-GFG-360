// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for(int i = 0; i < startTime.size() - 1; i++) 
            gaps.push_back(startTime[i + 1] - endTime[i]);
        gaps.push_back(eventTime - endTime.back());
        int ans = 0;
        for(int i = 0; i < k + 1; i++)
            ans += gaps[i];
        int sum = ans;
        for(int i = k + 1; i < gaps.size(); i++) {
            sum += gaps[i] - gaps[i - k - 1];
            ans = max(ans, sum);
        }
        return ans;
    }
};