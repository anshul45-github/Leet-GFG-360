// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = nums[0];
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] == nums[high]) {
                ans = min(ans, nums[mid]);
                high--;
            }
            else if(nums[mid] < nums[high]) {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};