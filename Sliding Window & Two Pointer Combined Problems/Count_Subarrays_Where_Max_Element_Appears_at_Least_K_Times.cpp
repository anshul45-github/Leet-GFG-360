// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

#include<vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = nums[0];
        for(int i = 1; i < nums.size(); i++) 
            maxi = max(maxi, nums[i]);
        int cnt = 0;
        long long ans = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] == maxi)
                cnt++;
            while(cnt >= k) {
                if(nums[l] == maxi)
                    cnt--;
                l++;
            }
            if(cnt < k) 
                ans += r - l + 1;
        }
        return (1LL * nums.size() * (nums.size() + 1) / 2) - ans;
    }
};