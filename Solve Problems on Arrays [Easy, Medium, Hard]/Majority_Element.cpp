// https://leetcode.com/problems/majority-element/

#include<bits/stdc++.h>
using namespace std;

// Naive Approach: Sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }
};

// Better Approach: Hash Map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++) 
            mp[nums[i]]++;
        n = n >> 1;
        for(auto x: mp) {
            if(x.second > n) 
                return x.first;
        }
        return 0;
    }
};

// Optimal Approach: Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = INT_MAX;
        int freq = 1;
        for(int x : nums) {
            if(ans == x)
                freq++;
            else {
                if(--freq == 0) {
                    ans = x;
                    freq = 1;
                }
            }
        }
        return ans;
    }
};