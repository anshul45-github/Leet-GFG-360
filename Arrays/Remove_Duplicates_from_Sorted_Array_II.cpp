// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Medium

// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Clarification:

// Confused why the returned value is an integer but your answer is an array?

// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

// Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)

// int len = removeDuplicates(nums);

// Any modification to nums in your function would be known by the caller.

// Using the length returned by your function, it prints the first len elements.

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        for(int i = 0; i < nums.size();) {
            int x = nums[i];
            int cnt = 0;
            while(i < nums.size() && nums[i] == x) {
                cnt++;
                i++;
            }
            for(int j = 0; j < min(cnt, 2); j++, start++)
                nums[start] = x;
        }
        return start;
    }
};