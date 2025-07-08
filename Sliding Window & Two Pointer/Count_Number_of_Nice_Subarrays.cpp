// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l1 = 0;
        int l2 = 0;
        int odd1 = 0;
        int odd2 = 0;
        int ans = 0;
        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] % 2 == 1) {
                odd1++;
                odd2++;
            }
            while(odd1 > k) {
                if(nums[l1] % 2 == 1)
                    odd1--;
                l1++;
            }
            while(odd2 > k - 1) {
                if(nums[l2] % 2 == 1)
                    odd2--;
                l2++;
            }
            ans += l2 - l1;
        }
        return ans;
    }
};