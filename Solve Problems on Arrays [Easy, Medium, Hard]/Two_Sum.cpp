// https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target) 
                    return {i, j};
            }
        }
        return {}; // No solution found
    }
};

// Better Approach: Two Pass Hash Table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for(int i = 0; i < n; i++) 
            numMap[nums[i]] = i;

        // Find the complement
        for(int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if(numMap.count(complement) && numMap[complement] != i) 
                return {i, numMap[complement]};
        }

        return {}; // No solution found
    }
};

// Optimal Approach: One Pass Hash Table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(numMap.count(target - nums[i])) 
                return {numMap[target - nums[i]], i};
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};