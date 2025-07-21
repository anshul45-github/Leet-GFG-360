// https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findCeil(vector<int>& nums, int target, int low) {
        int high = nums.size() - 1;
        int ans = low;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] > target) {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) 
            i--;
        if(i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int u = findCeil(nums, nums[i], i + 1);
        swap(nums[i], nums[u]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};