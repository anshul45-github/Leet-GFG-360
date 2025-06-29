// https://leetcode.com/problems/max-consecutive-ones/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int end = 0;
        int ans = 0;
        while(end < nums.size()) {
            if(nums[end] == 1) {
                int start = end;
                while(end < nums.size() && nums[end] == 1)
                    end++;
                ans = max(ans, end - start);
            }
            end++;
        }
        return ans;
    }
};