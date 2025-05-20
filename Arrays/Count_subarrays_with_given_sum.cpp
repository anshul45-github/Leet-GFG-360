// https://leetcode.com/problems/subarray-sum-equals-k/
// 560. Subarray Sum Equals K
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sums;
        int n = nums.size();
        int sum = 0;
        int subarrays = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum == k)
                subarrays++;
            if(sums[sum - k])
                subarrays += sums[sum - k];    
            sums[sum]++;       
        }
        return subarrays;
    }
};
