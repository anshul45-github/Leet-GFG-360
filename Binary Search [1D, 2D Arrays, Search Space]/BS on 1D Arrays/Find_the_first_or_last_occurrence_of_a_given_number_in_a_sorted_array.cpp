// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        vector<int> ans = {-1, -1};
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] >= target) {
                ans[0] = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] <= target) {
                ans[1] = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if(ans[0] != -1 && nums[ans[0]] != target) 
            ans[0] = -1;
        if(ans[1] != -1 && nums[ans[1]] != target)
            ans[1] = -1;
        return ans;
    }
};