// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] == target)
                return true;
            else if(nums[mid] == nums[high])
                high--;
            else if(nums[mid] < nums[high]) {
                if(nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else {
                if(target < nums[mid] && nums[low] <= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return false;
    }
};