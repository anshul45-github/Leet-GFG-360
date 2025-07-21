// https://leetcode.com/problems/sum-of-unique-elements/
// Easy

// Given an integer array nums, return the sum of all unique elements in nums.

// An element of an array is unique if it appears exactly once in the array.

// Example 1:
// Input: nums = [1,2,3,2]
// Output: 4
// Explanation: The unique elements are [1,3], and the sum is 4.

// Example 2:
// Input: nums = [1,1,1,1,1]
// Output: 0
// Explanation: There are no unique elements, and the sum is 0.

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        for(int x : nums) 
            mp[x]++;
        for(auto& p : mp) {
            if(p.second == 1)
                sum += p.first;
        }
        return sum;
    }
};