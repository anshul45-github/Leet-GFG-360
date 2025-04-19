// https://leetcode.com/problems/find-peak-element/
// 162. Find Peak Element
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            bool left = (mid == 0) || ((mid > 0) && (nums[mid] > nums[mid - 1]));
            bool right = (mid == nums.size() - 1) || (mid < nums.size() - 1) && ((nums[mid] > nums[mid + 1]));
            if(left && right)
                return mid;
            else if(!left)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};