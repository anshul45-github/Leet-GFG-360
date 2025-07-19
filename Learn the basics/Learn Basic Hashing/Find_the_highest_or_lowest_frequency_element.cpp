// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long i = 0, j = 1, maxlen = 1, needed = 0, K = k;
        sort(nums.begin(), nums.end());
        while(j < nums.size()) {
            needed += (j - i) * (nums[j] - nums[j - 1]);
            while(needed > K && i < j) {
                needed -= nums[j] - nums[i];
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};
