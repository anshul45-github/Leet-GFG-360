// https://leetcode.com/problems/task-scheduler/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Using Priority Queue
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> v(26, 0);

        for(char &ch : tasks) 
            v[ch - 'A']++;

        priority_queue<int> pq;
        for(int i = 0; i < 26; i++){
            if(v[i] > 0) 
                pq.push(v[i]);
        }

        while(!pq.empty()){
            vector<int> temp;

            // Doing tasks
            for(int i = 0; i <= n; i++) {
                if(!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &i : temp){
                if(i > 0) 
                    pq.push(i);
            }

            
            if(pq.empty())      // Last set of tasks
                ans += temp.size();
            else                // Did (n + 1) tasks
                ans += (n+1);
        }
        return ans;
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