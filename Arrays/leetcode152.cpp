#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNO = INT_MIN;
        int n = nums.size();
        int prod = 1;
        for(int i = 0; i < n; i++) {
            prod *= nums[i];
            maxNO = max(prod, maxNO);
            if(prod == 0)
                prod = 1;
        }
        prod = 1;
        for(int i = n - 1; i >= 0; i--) {
            prod *= nums[i];
            maxNO = max(prod, maxNO);
            if(prod == 0)
                prod = 1;
        }
        return maxNO;
    }
};
