// https://leetcode.com/problems/move-zeroes/
// 283. Move Zeroes
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(i < nums.size() && nums[i] != 0)
            i++;
        int init = i;
        for(; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[init]);
                init++;
            }
        }
    }
};