#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        for(int r = 0; r < n; r++) {
            if(nums[r] != 0) {
                swap(nums[r], nums[l]);
                l++;
            }
        }
    }
};
