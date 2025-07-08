// https://leetcode.com/problems/minimum-size-subarray-sum/

#include<bits/stdc++.h>
using namespace std;

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