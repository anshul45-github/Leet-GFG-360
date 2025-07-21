// https://leetcode.com/problems/sort-colors/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Counting Sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> count;

        for(int num : nums) 
            count[num]++;

        int idx = 0;
        for(int color = 0; color < 3; color++) {
            int freq = count[color];
            for(int j = 0; j < freq; j++) {
                nums[idx] = color;
                idx++;
            }
        }        
    }
};

// Approach 2: Two Pointers (Dutch National Flag Problem)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size() - 1;
        while(j <= k) {
            if(nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            }
            else if(nums[j] == 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else
                j++;
        }
    }
};