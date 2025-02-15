#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> exists(nums.size(), false);
        for(int i = 0; i < nums.size(); i++) {
            if(exists[nums[i]])
                return nums[i];
            exists[nums[i]] = true;
        }
        return 1;
    }
};