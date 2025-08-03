// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long start = -1;
        long long maxi = -1;
        long long mini = -1;
        long long cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < minK || nums[i] > maxK)
                start = i;
            if(nums[i] == minK)
                mini = i;
            if(nums[i] == maxK)
                maxi = i;
            cnt += max(0LL, min(mini, maxi) - start);
        }
        return cnt;
    }
};