// https://leetcode.com/problems/two-sum/
// Easy

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> a(2);
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(target - nums[i]) && mp[target - nums[i]] != i) {
                a[0] = mp[target - nums[i]];
                a[1] = i;
                return a;
            }
        }
        return a;
    }
};