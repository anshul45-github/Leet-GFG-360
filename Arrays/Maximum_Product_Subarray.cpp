// https://leetcode.com/problems/maximum-product-subarray/description/
// 152. Maximum Product Subarray
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int leftProd = 1;
        int rightProd = 1;
        for(int i = 0; i < nums.size(); i++) {
            leftProd *= nums[i];
            rightProd *= nums[nums.size() - i - 1];
            maxi = max(maxi, leftProd);
            maxi = max(maxi, rightProd);
            if(leftProd == 0)
                leftProd = 1;
            if(rightProd == 0)
                rightProd = 1;
        }
        return maxi;
    }
};