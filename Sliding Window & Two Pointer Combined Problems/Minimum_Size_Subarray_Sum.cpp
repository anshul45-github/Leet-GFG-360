// https://leetcode.com/problems/minimum-size-subarray-sum/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Prefix Sum and Binary Search
class Solution {
    int floor(vector<int>& prefixSum, int target) {
        int low = 0, high = prefixSum.size() - 1, ans = -1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(prefixSum[mid] <= target) {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefixSum;
        int currSum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            currSum += x;
            int floorIdx = floor(prefixSum, currSum - target);
            if(floorIdx != -1)
                ans = min(ans, i - floorIdx);
            else if(currSum >= target)
                ans = min(ans, i + 1);
            prefixSum.push_back(currSum);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// Optimized Approach: Using Sliding Window Technique
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