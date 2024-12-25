#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for(int i = 0; i < k; i++) {
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> maxi = {nums[q.front()]};
        for(int i = k; i < nums.size(); i++) {
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            while(q.front() <= i - k) {
                q.pop_front();
            }
            maxi.push_back(nums[q.front()]);
        }
        return maxi;
    }
};
