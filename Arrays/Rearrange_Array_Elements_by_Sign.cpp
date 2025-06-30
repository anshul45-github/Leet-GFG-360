// https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int p = 0;
        int n = 1;
        for(int x : nums) {
            if(x < 0) {
                ans[n] = x;
                n += 2;
            }
            else {
                ans[p] = x;
                p += 2;
            }
        }
        return ans;
    }
};