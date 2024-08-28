#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroes = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0)
                zeroes++;
            else
                nums[i - zeroes] = nums[i];
        }
        for(int i = n - zeroes; i < n; i++) {
            nums[i] = 0;
        }
    }
};
