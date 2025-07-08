// https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=prefix-sum

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while(sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            if(sum >= target)
                ans = min(ans, right - left + 1);
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};