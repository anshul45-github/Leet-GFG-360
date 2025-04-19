// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// 34. Find First and Last Position of Element in Sorted Array
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            vector<int> v = {-1, -1};
            return v;
        }
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            int mid = l + ((r - l) >> 1);
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if(nums[r] != target) {
            vector<int> v = {-1, -1};
            return v;
        }
        int first = r;
        l = 0;
        r = nums.size() - 1;
        while(l < r) {
            int mid = l + ((r - l) >> 1) + 1;
            if(nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        return {first, l};
    }
};