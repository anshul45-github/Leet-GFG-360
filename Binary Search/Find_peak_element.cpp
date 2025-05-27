// https://leetcode.com/problems/find-peak-element/
// Medium

// This code finds a peak element in an array using binary search.

// A peak element is an element that is greater than its neighbors.

// The function `findPeakElement` takes a vector of integers `nums` as input and returns the index of a peak element.

// The search space is from 0 to `nums.size() - 1`, and the mid-point is calculated using bitwise operations for efficiency.

// The function checks if the left neighbor is greater than the current element and if the right neighbor is greater than the current element.

// If both conditions are true, it returns the index of the current element as a peak.

// If the left neighbor is lesser, it means we need to search in the right half of the array, so we update `l` to `mid + 1`.

// If the right neighbor is lesser, it means we need to search in the left half of the array, so we update `r` to `mid - 1`.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool leftGreater(vector<int>& nums, int idx) {
        if(idx - 1 < 0)
            return true;
        if(nums[idx] > nums[idx - 1])
            return true;
        return false;
    }
    bool rightGreater(vector<int>& nums, int idx) {
        if(idx + 1 >= nums.size())
            return true;
        if(nums[idx] > nums[idx + 1])
            return true;
        return false;
    }
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(leftGreater(nums, mid) && rightGreater(nums, mid))
                return mid;
            else if(leftGreater(nums, mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};