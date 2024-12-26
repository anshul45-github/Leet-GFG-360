#include<bits/stdc++.h>
using namespace std;

class Solution {
    int sumLessThanEqual(vector<int>& nums, int goal) {
        if(goal == -1)
            return 0;
        int start = 0;
        int ans = 0;
        int sum = 0;
        for(int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            while(sum > goal && start < nums.size()) {
                sum -= nums[start];
                start++;
            }
            if(end - start + 1 > 0)
                ans += end - start + 1;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumLessThanEqual(nums, goal) - sumLessThanEqual(nums, goal - 1);
    }
};
