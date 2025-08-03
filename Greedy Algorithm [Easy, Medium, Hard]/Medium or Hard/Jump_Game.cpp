// https://leetcode.com/problems/jump-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0; i <= min(maxReach, (int)nums.size() - 1); i++) 
            maxReach = max(maxReach, i + nums[i]);
        return maxReach >= nums.size() - 1;
    }
};