// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = nums[0];
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            ans = min(ans, nums[mid]);
            if(nums[mid] < nums[high]) 
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
};