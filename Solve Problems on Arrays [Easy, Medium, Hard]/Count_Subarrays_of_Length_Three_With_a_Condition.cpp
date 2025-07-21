// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/
// 3392. Count Subarrays of Length Three With a Condition
// Easy

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(2 * (nums[i] + nums[i + 2]) == nums[i + 1])
                cnt++;
        }
        return cnt;
    }
};