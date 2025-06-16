// https://leetcode.com/problems/maximum-difference-between-increasing-elements/
// Easy

// Problem Statement:
// Given a 0-indexed integer array nums, return the maximum difference between nums[i] and nums[j] (i < j) such that nums[i] < nums[j].
// If no such i and j exists, return -1.

// Example 1:
// Input: nums = [7,1,5,4]
// Output: 4
// Explanation: The maximum difference is between nums[1] and nums[2] (i = 1, j = 2) with a difference of 5 - 1 = 4.

// Example 2:
// Input: nums = [9,4,3,2]
// Output: -1
// Explanation: There are no i and j such that nums[i] < nums[j], so we return -1.

#include <vector>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int prefix = nums[0];
        int ans = -1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > prefix)
                ans = max(ans, nums[i] - prefix);
            prefix = min(prefix, nums[i]);
        }
        return ans;
    }
};