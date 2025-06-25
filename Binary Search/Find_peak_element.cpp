// https://leetcode.com/problems/find-peak-element/

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