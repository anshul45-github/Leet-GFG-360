#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        priority_queue<int, vector<int>, less<int>> pq;
        for(const auto& pair : mp) {
            pq.push(pair.second);
        }
        int totalTime = 0;
        while(!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for(int i = 0; i < n + 1; i++) {
                if(!pq.empty()) {
                    int p = pq.top();
                    tmp.push_back(p);
                    pq.pop();
                    time++;
                }
            }
            for(int i : tmp) {
                if(--i)
                    pq.push(i);
            }
            totalTime += !pq.empty() ? n + 1 : time;
        }
        return totalTime;
    }
};
