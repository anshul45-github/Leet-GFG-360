#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int idx = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != curr) {
                nums[idx] = nums[i];
                idx++;
                curr = nums[i];
            }
        }
        return idx;
    }
};
