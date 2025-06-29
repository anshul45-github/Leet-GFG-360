// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()) {
            while(j + 1 < nums.size() && nums[j] == nums[j + 1])
                j++;
            nums[i] = nums[j];
            i++;
            j++;
        }
        return i;
    }
};