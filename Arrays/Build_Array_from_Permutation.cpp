// https://leetcode.com/problems/build-array-from-permutation/
// 1920. Build Array from Permutation
// Easy

// Given a zero-based permutation nums (0-indexed), build an array ans of the same size where ans[i] = nums[nums[i]] for each 0 <= i < nums.length() and return it.

// A zero-based permutation nums is an array of distinct integers which are present in the range [0, nums.length - 1] inclusive.

// You must write an algorithm that runs in O(n) time and uses O(1) space.

// Example 1:
// Input: nums = [0,2,1,5,3,4]
// Output: [0,1,2,4,5,3]
// Explanation: The array ans is built as follows:
// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
//     = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
//     = [0,1,2,4,5,3]

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            nums[i] += (nums[nums[i]] % nums.size()) * nums.size();
        for(int i = 0; i < nums.size(); i++)
            nums[i] /= nums.size();
        return nums;
    }
};