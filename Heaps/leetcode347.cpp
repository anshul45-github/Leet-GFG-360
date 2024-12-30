#include<bits/stdc++.h>
using namespace std;

class cmp {
public:
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        return p2.second < p1.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(auto p : mp) {
            pq.push(p);
        }
        while(pq.size() > k)
            pq.pop();
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
