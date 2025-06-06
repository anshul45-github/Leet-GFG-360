// https://leetcode.com/problems/count-number-of-nice-subarrays/
// Medium

// Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.

// Return the number of nice subarrays.

// A subarray is a contiguous part of an array.

// Example 1:
// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only subarrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

// Example 2:
// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There is no odd numbers in the array.

// Example 3:
// Input: nums = [2,2,2,1,2,2,1,2,2], k = 2
// Output: 16
// Explanation: The odd numbers in the array are [1,1]. There are 16 subarrays that have 2 odd numbers.

// Constraints:
// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length

// Accepted

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