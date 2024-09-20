#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        if(nums[0] > target)
            return 0;
        if(nums[n - 1] < target)
            return n;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return mid;
            if(mid > 0 && (nums[mid] > target && nums[mid - 1] < target))
                return mid;
            if(mid < n - 1 && (nums[mid] < target && nums[mid + 1] > target))
                return mid + 1;
            if(nums[mid] < target)
                l = mid + 1;
            else if(nums[mid] > target)
                r = mid - 1;
        }
        return -1;
    }
};
