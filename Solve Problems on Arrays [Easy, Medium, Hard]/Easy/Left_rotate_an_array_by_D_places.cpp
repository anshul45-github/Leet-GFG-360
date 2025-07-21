// https://leetcode.com/problems/rotate-array/

#include<bits/stdc++.h>
using namespace std;

// Approach 1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i = 0; i < nums.size(); i++)
            temp[(i + k) % nums.size()] = nums[i];
        for(int i = 0; i < nums.size(); i++)
            nums[i] = temp[i];
    }
};

// Approach 2
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k != 0) {
            vector<int> temp(nums.end() - k, nums.end());
            temp.insert(temp.end(), nums.begin(), nums.end() - k);
            copy(temp.begin(), temp.end(), nums.begin());
        }        
    }
};

// Approach 3 (Optimal)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());  
    }
};