// https://leetcode.com/problems/count-the-number-of-fair-pairs
// 2563. Count the Number of Fair Pairs
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int ul = upper - nums[i];
            int ll = lower - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while(l <= r) {
                int mid = l + ((r - l) >> 1);
                if(nums[mid] > ul)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            ul = r;
            l = i + 1;
            r = nums.size() - 1;
            while(l <= r) {
                int mid = l + ((r - l) >> 1);
                if(nums[mid] < ll)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            ll = l;
            ans += ul - ll + 1;
        }
        return ans;
    }
};