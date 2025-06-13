// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
// Medium

// Given an integer array nums of size n and an integer p, return the minimum possible value of the maximum difference between pairs in nums after selecting p pairs.

// A pair (nums[i], nums[j]) is called a pair if i < j. The maximum difference between pairs is the maximum value of |nums[i] - nums[j]| over all pairs (i, j). 

// The maximum difference between pairs is the maximum value of |nums[i] - nums[j]| over all pairs (i, j).

// Constraints:
// 1 <= n == nums.length <= 10^5
// 0 <= nums[i] <= 10^9
// 0 <= p <= n / 2
// The input is generated such that it is possible to select p pairs.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p == 0) 
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n - 1] - nums[0];
        int ans = right;
        while(left <= right) {
            int mid = left + (right - left) / 2, pairs = 0;
            for(int i = 1; i < n; ++i) {
                if(mid >= nums[i] - nums[i - 1]) {
                    ++pairs, ++i;
                }
            }
            if(pairs >= p) {
                right = mid - 1;
                ans = mid;
            }
            else 
                left = mid + 1;
        }
        return ans;
    }
};