#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dpInc(n, 1);
        vector<int> dpDec(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j])
                    dpInc[i] = max(dpInc[i], dpInc[j] + 1);
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j > i; j--) {
                if(nums[i] > nums[j])
                    dpDec[i] = max(dpDec[i], dpDec[j] + 1);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dpInc[i] > 1 && dpDec[i] > 1)
                ans = max(ans, dpInc[i] + dpDec[i] - 1);
        }
        return ans;
    }
};
