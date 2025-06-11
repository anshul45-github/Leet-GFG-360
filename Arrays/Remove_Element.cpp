// https://leetcode.com/problems/remove-element/description/
// Easy

// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the following example:

// Example 1:
// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2]
// Explanation: Your function should return length = 2, with the first two elements of nums being 2.
// It doesn't matter what you leave beyond the returned length.

// Example 2:
// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,3,0,4]
// Explanation: Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
// It doesn't matter what values are set beyond the returned length.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size() - 1;
        for(int i = 0; i <= last;) {
            if(nums[i] == val) {
                swap(nums[i], nums[last]);
                last--;
            }
            else
                i++;
        }
        return last + 1;
    }
};