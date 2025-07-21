// https://leetcode.com/problems/longest-consecutive-sequence/

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach - TLE
class Solution {
    bool find(vector<int>& nums, int target){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target)
                return true;
        }
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(auto x : nums) {
            int curr = x;
            int currLen = 1;
            while(find(nums, curr + 1)) {
                curr++;
                currLen++;
            }
            ans = max(ans, currLen);
        }
        return ans;
    }
};

// Better Approach - Sorting
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) 
            return 0;
        sort(nums.begin(), nums.end());
        int curr = 1;
        int ans = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1]) {
                if(nums[i] == nums[i - 1] + 1)
                    curr++;
                else {
                    ans = max(ans, curr);
                    curr = 1;
                }
            }
        }
        return max(ans, curr);
    }
};

// Optimal Approach - Using Hashing
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 1;
        for(int x : s) {
            if(s.find(x - 1) == s.end()) {
                int cnt = 1;
                while(s.find(x + cnt) != s.end())
                    cnt++;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};