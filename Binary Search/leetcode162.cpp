#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        if(h == 0) {
            return 0;
        }
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            if(mid == 0 && nums[mid] > nums[mid + 1])
                return mid;
            else if(mid == nums.size() - 1 && nums[mid] > nums[mid - 1])
                return mid;
            else if(mid > 0 && mid < nums.size() - 1 && nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;
            else if(mid < nums.size() - 1 && nums[mid + 1] > nums[mid])
                l = mid + 1;
            else
                h = mid;
        }
        return -1;
    }
};
