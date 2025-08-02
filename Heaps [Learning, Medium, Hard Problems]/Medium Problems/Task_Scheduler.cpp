// https://leetcode.com/problems/task-scheduler/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Using Priority Queue
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(char task : tasks) 
            freq[task]++;

        // Max heap for frequencies (use negative to simulate max-heap)
        priority_queue<int> maxHeap;
        for(auto entry : freq) 
            maxHeap.push(entry.second);

        int time = 0;

        while(!maxHeap.empty()) {
            vector<int> temp;
            int cycle = n + 1;

            // Try to run up to n+1 tasks in each cycle
            while(cycle > 0 && !maxHeap.empty()) {
                int curr = maxHeap.top(); maxHeap.pop();
                if(curr > 1) 
                    temp.push_back(curr - 1);
                time++;
                cycle--;
            }

            // Push remaining back into heap
            for(int remaining : temp) 
                maxHeap.push(remaining);

            // If tasks remain and we used less than n+1 time, we need idle time
            if(!maxHeap.empty()) 
                time += cycle; // add idle time
        }

        return time;
    }
};

// Approach 2 - Greedy Algorithm
class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();

        if(p == 0) 
            return tasks.size();
        
        vector<int> counter(26,0);
        for(char& ch : tasks)
            counter[ch - 'A']++;
        
        sort(begin(counter), end(counter));
        
        // Highest Count at end
        int chunks = counter[25] - 1;
        int idolSpots = chunks * p;
        
        for(int i = 24; i >= 0; i--)
            idolSpots -= min(chunks, counter[i]);
        
        if(idolSpots > 0) 
            return n + idolSpots;
        
        return n;
    }
};

// Approach 3 - Using HashMap
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> mp;
        int maxFreq = 0;
        int maxFreqCnt = 0;
        for(char task : tasks) {
            mp[task]++;
            if(mp[task] > maxFreq) {
                maxFreq = mp[task];
                maxFreqCnt = 1;
            }
            else if(mp[task] == maxFreq)
                maxFreqCnt++;
        }
        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxFreqCnt);
    }
};