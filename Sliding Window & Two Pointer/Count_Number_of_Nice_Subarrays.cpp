// https://leetcode.com/problems/count-number-of-nice-subarrays/
// 1248. Count Number of Nice Subarrays
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int atMost(vector<int>& nums, int k) {
        int oddVal = 0;
        int start = 0;
        int ans = 0;
        for(int end = 0; end < nums.size(); end++) {
            if(nums[end] & 1)
                oddVal++;
            while(oddVal > k) {
                if(nums[start] & 1)
                    oddVal--;
                start++;
            }
            ans += end - start + 1;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
