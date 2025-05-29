// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Medium

// This code searches for a target value in a rotated sorted array that may contain duplicates.

// The function `search` takes a vector of integers `nums` and an integer `target` as input and returns true if the target is found, otherwise false.

// The search space is from 0 to `nums.size() - 1`, and the mid-point is calculated using bitwise operations for efficiency.

// The function handles duplicates by checking if the leftmost element is equal to the mid-point element and adjusting the search space accordingly.

// It checks if the left half of the array is sorted and if the target lies within that range.

// If it does, it narrows the search space to the left half; otherwise, it searches in the right half.

// The time complexity is O(log n) in the average case, but can degrade to O(n) in the worst case due to duplicates.

// The space complexity is O(1) since no additional data structures are used.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[l]) {
                l++;
                continue;
            }
            if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else {
                if(nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};