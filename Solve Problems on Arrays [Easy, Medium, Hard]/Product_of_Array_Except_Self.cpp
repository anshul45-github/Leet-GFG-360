// https://leetcode.com/problems/product-of-array-except-self/
// Medium

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Explanation: The product of all the elements except nums[0] is 2*3*4 = 24.
// The product of all the elements except nums[1] is 1*3*4 = 12.
// The product of all the elements except nums[2] is 1*2*4 = 8.
// The product of all the elements except nums[3] is 1*2*3 = 6.

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product(nums.size(), 1);
        int p = nums[0];
        for(int i = 1; i < product.size(); i++) {
            product[i] = p;
            p *= nums[i];
        }
        p = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--) {
            product[i] *= p;
            p *= nums[i];
        }
        return product;
    }
};