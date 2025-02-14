#include<bits/stdc++.h>
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
