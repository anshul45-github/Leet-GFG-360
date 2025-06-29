// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                int k = 0;
                int j = i + 1;
                while(k < nums.size() - 1) {
                    int next = (j + 1) % nums.size();
                    if(nums[j] > nums[next])
                        return false;
                    j = next;
                    k++;
                }
                return true;
            }
        }
        return true;
    }
};