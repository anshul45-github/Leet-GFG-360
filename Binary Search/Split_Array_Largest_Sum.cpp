// https://leetcode.com/problems/split-array-largest-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(vector<int> nums, int maxSum, int n, int k) {
        int sum = 0;
        int noOfSubarrays = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > maxSum)
                return false;
            sum += nums[i];
            if(sum > maxSum) {
                noOfSubarrays++;
                sum = nums[i];
            }
        }
        return noOfSubarrays <= k - 1;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];
        int l = 0;
        int h = sum;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);
            if(helper(nums, mid, n, k)) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
