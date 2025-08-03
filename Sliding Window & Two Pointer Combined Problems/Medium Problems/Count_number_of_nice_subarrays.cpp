// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums, int k) {
        int l = 0;
        int odd = 0;
        int ans = 0;
        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] % 2 == 1)
                odd++;
            while(odd > k) {
                if(nums[l] % 2 == 1)
                    odd--;
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};