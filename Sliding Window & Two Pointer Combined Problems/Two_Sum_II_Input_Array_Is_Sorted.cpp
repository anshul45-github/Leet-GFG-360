// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int l = 0;
            int r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] == target) {
                    vector<int> v = {l + 1, r + 1};
                    return v;
                }
                else if(nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
            vector<int> v = {-1, -1};
            return v;
        }
    };