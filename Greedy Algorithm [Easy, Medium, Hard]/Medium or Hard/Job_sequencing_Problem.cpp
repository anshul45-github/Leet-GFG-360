// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        int sum = 0;
        int count = 0;
        vector<pair<int,int>> Job;
        for(int i = 0; i < n; i++){
            pair<int,int> p = make_pair(deadline[i], profit[i]);
            Job.push_back(p);
        }
        sort(Job.begin(), Job.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i = 0; i < n; i++) {
           if(Job[i].first > count) {
               count++;
               sum += Job[i].second;
               pq.push(Job[i].second);
           }
           else if(Job[i].second > pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += Job[i].second;
                pq.push(Job[i].second);
           }
        }
        return {count, sum};
    }
};