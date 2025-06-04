// https://leetcode.com/problems/binary-subarrays-with-sum/
// 930. Binary Subarrays With Sum
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        int sum = 0;
        int l = 0;
        int ans = 0;
        for(int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while(sum > k) {
                sum -= nums[l];
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};