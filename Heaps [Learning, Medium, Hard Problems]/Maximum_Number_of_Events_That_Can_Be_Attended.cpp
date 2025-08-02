// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by their start time, and if equal, by their end time
        sort(events.begin(), events.end());        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int day = 0, index = 0, n = events.size(), result = 0;
        while(!minHeap.empty() || index < n) {
            if(minHeap.empty()) 
                day = events[index][0];
            while (index < n && events[index][0] <= day) {
                minHeap.push(events[index][1]);
                index++;
            }
            minHeap.pop();
            result++;
            day++;
            while(!minHeap.empty() && minHeap.top() < day) 
                minHeap.pop();
        }
        return result;
    }
};