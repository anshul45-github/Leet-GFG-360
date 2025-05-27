// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Medium

// This code searches for a target value in a rotated sorted array using binary search.

// The function `search` takes a vector of integers `nums` and an integer `target` as input and returns the index of the target if found, otherwise -1.

// The search space is from 0 to `nums.size() - 1`, and the mid-point is calculated using bitwise operations for efficiency.

// The function checks if the left half of the array is sorted and if the target lies within that range.

// If it does, it narrows the search space to the left half; otherwise, it searches in the right half.

#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(nums[mid] == target)
                return mid;
            else if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && nums[mid] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else {
                if(nums[r] >= target && nums[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    } 
};