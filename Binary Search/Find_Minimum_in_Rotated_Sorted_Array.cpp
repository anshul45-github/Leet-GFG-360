// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Medium

// This code finds the minimum element in a rotated sorted array.

// The function `findMin` takes a vector of integers `nums` as input and returns the minimum element.

// It uses a binary search approach to efficiently locate the minimum element.

// The search space is defined by two pointers, `l` and `r`, which represent the left and right bounds of the current search range.

// The mid-point is calculated using bitwise operations for efficiency.

// The function checks if the left half of the array is sorted and adjusts the search space accordingly.

// If the left half is sorted, it checks if the minimum element lies in the right half.

// If the left half is not sorted, it narrows the search space to the left half.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            int mid = l + ((r - l ) >> 1);
            if(l == mid) 
                return min(nums[l], nums[r]);
            if(nums[l] <= nums[mid]) {
                if(nums[l] < nums[r])
                    r = mid;
                else
                    l = mid;
            }
            else
                r = mid;
        }
        return nums[r];
    }
};