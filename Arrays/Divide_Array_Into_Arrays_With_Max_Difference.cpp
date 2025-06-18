// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
// Medium

// Given an integer array nums of size n, divide it into one or more arrays such that each array contains exactly three elements and the maximum difference between the largest and smallest element in each array is at most k. Return a list of arrays that satisfy this condition. If it is not possible to divide the array, return an empty list.

// Example 1:
// Input: nums = [1, 2, 3, 4, 5, 6], k = 2
// Output: [[1, 2, 3], [4, 5, 6]]
// Explanation: The maximum difference in the first array is 2 (3 - 1) and in the second array is also 2 (6 - 4).

// Example 2:
// Input: nums = [1, 2, 3, 4, 5], k = 1
// Output: []
// Explanation: It is not possible to divide the array into arrays of three elements with a maximum difference of 1.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i += 3) {
            if(nums[i + 2] - nums[i] > k)
                return {};
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};