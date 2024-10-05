#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int r = nums.size() - 1;
        int l = 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2) {
            return nums[1] > nums[0] ? nums[0] : nums[1];
        }
        if(nums[0] < nums[r])
            return nums[0];
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums[r] || mid == r) {
                if(nums[mid] < nums[mid - 1])
                    return nums[mid];
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return nums[nums.size() - 1];
    }
};
