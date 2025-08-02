// https://leetcode.com/problems/sum-of-subarray-ranges/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> next(nums.size());
        vector<int> prev(nums.size());
        stack<int> st;
        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if(st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = nums.size() - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if(st.empty())
                next[i] = nums.size();
            else
                next[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) 
            ans += 1LL * nums[i] * (next[i] - i) * (i - prev[i]);
        while(!st.empty())
            st.pop();
        for(int i = nums.size() - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if(st.empty())
                next[i] = nums.size();
            else
                next[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if(st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < nums.size(); i++) 
            ans -= 1LL * nums[i] * (next[i] - i) * (i - prev[i]);
        return ans;
    }
};